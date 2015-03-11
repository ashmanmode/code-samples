#include "Outlook.h"

using namespace std;
using namespace cv;

extern ofstream logfile;

/* global declarations for Interactive tools */
//temporary point storage
vector<Point2f> points;      

// these colors are used in line drawing and rectangle drawings
const CvScalar g_COLORS[10] = {
	CV_RGB( 220,  20,  60 ),
	CV_RGB( 255, 255,   0 ),
	CV_RGB( 255,   0, 255 ),
	CV_RGB(  30, 144, 255 ),
	CV_RGB( 255, 165,   0 ),
	CV_RGB(   0, 250, 154 ),
	CV_RGB(   0, 255, 255 ),
	CV_RGB( 175, 255,   0 ),
	CV_RGB( 138,  51,  36 ),
	CV_RGB(   0, 255,  10 )};

int color_count;             
int object_count  = 0; 

//global functions 
double GetResizeRatio( Mat img );

void MouseCallbackFunction( int event, int x, int y, int flag, void *param )
{
	Point2f pt;
	pt.x = (float) x;
	pt.y = (float) y;

	if( CV_EVENT_LBUTTONDOWN == event )
	{
		points.push_back( pt );
		color_count ++ ; 
	}
}

//! SetImage will take Mat file as input image and store in COutlook class 
/*
\param InputImage is the input image file to be stored in class
*/
void COutlook::SetImage( Mat InputImage )
{
	original_image = InputImage;
}

//! FindRotationWithHomography will find the rotation matrices of all the images using homography 
/*
This function uses homography between two images to compute the rotation matrix , 
it again assumes the rotaion matrix of image 1 as unity
\param CamMat It is the camera Intrinsic Matrix (same for all panaromas)
\param i is the no of image in sequence
\param prev_img is a pointer to the Coutlook class of previous image
*/
void COutlook::FindRotationWithHomography( Mat CamMat , COutlook *prev_img )
{
	if(NULL == prev_img )
		rotation_mat = Mat::eye(3,3,CV_32FC1);
	else
	{
		color_count = 0 ;
		points.clear();
		
		// Forming a combines image from image1 and image 2
		Mat img1 = ( *prev_img ).original_image.clone();
		Mat img2 = original_image.clone();
		Mat combine( img1.rows, img1.cols + img2.cols, img1.type() );
		for ( int k = 0; k < combine.cols; k++ )
		{
			if ( k < img1.cols )
			{
				img1.col( k ).copyTo( combine.col( k ) );
			}
			else
			{
				img2.col( k - img1.cols ).copyTo( combine.col( k ) );
			}
		}

		//creating and resize the window which can be displayed in the client area of the screen
		namedWindow( "Rotation Finding Tool", CV_WINDOW_NORMAL );
		resizeWindow( "Rotation Finding Tool", (int)( combine.cols * GetResizeRatio( combine ) ), (int)( combine.rows * GetResizeRatio( combine )));

		cout << "Welcome again. Help me find Rotation Matrix. Mark the common points points " << endl;
		do 
		{
			imshow ( "Rotation Finding Tool", combine );
			cvSetMouseCallback( "Rotation Finding Tool", MouseCallbackFunction );
			if ( 1 == color_count % 2 )
			{
				circle( combine, points[ color_count - 1 ], 5, CV_RGB(255,0,0), 5, 8, 0 );
			}
			else if ( 0 == color_count % 2 && color_count > 0)
			{
				circle( combine, points[ color_count - 1 ], 5, CV_RGB(255,0,0), 5, 8, 0 );
				line( combine, points[ color_count - 2 ], points[ color_count - 1 ], g_COLORS[ ( color_count/2 ) % 10 ], 2, CV_AA, 0 );
			}
			if( 27 == waitKey(1) )
			{
				destroyWindow( "Rotation Finding Tool" );
				break;
			}
		}while(1);

		Point2f temp;
		vector < Point2f > src,dst;

		//we will only take even no of points 
		int no_points;
		if( 1 == points.size() % 2 )
		{
			no_points = points.size() - 1;
		}
		else
		{
			no_points = points.size();
		}

		//now looping to push respective points in a vector
		for ( int k = 0; k < no_points ; k++ )
		{
			if ( 0 == k % 2 )
			{
				src.push_back( points[k] );
			}
			else 
			{
				temp.x = points[k].x - img1.cols;
				temp.y = points[k].y;
				dst.push_back( temp );
			}
		}
		points.clear();

		Mat H = findHomography( src, dst, CV_RANSAC, 3);
		if ( H.empty() )
		{
			logfile << "Could not find the  homography from no. of common points provided " << endl;
		}
		Mat H_transformed;
		H.convertTo( H_transformed, CV_32FC1 );
		rotation_mat = ( ( (*prev_img).rotation_mat.t() ).inv() ) * ( CamMat.inv() * ( H_transformed * CamMat ) );
	}

	logfile << "Rotation Mat  " << endl << rotation_mat << endl << endl;
}

//! Annotate view will launch a interactive tool to takes user inputs.
/*
\sa GetRect, GetLine are the child functions to this function
*/
void COutlook::AnnotateView()
{
	cout << "*******************************************************************" << endl;
	cout << " Welcome This is the interactive tool to take rectangles from user " << endl;

	Mat cloneimg = original_image.clone();

	namedWindow( "Interactive tool", CV_WINDOW_NORMAL );
	resizeWindow( "Interactive tool", (int)( GetResizeRatio( original_image ) * original_image.cols ), (int)( GetResizeRatio( original_image ) * original_image.rows ) );
	imshow( "Interactive tool", cloneimg );

	//char choice;
	do
	{
		//cout << "Press r ( Rectangle ) , l (Line)  or anything other to Finish" << endl;
		//cin >> choice;
		int message = MessageBox( 0, L"Press 'Yes' if you want to draw rectangle\nPress 'No' if you want to draw pair of parallel lines\nTo finish drawing for this image press 'Cancel'", L"Your Choice", MB_YESNOCANCEL | MB_ICONQUESTION | MB_TASKMODAL );
		if( IDYES == message )
		{
			cloneimg = GetRect( cloneimg );
		}
		else if( IDNO == message )
		{
			cloneimg = GetLine( cloneimg );
		}
		else 
		{
			destroyWindow( "Interactive tool" );
			break;
		}
	} while(1);

	logfile << " Lines and Rects Successfully Recorded " << endl; 
}

//! GetResizeRatio is a private function which find the image size reduction ratio needed
/*
GetResizeRatio is a private function which find the scale to which input 
image size should be reduced so that it viwable on the screen
\return Resize ratio in datatype double
*/
double GetResizeRatio( Mat img )
{
	double resize_ratio;
	Size img_size = img.size();
	int window_width, window_height;

	RECT desktop;
	RECT taskbar;

	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	const HWND hTask = FindWindow( L"Shell_traywnd", NULL );

	// Get the size of screen to the variable desktop
	GetWindowRect( hDesktop, &desktop );
	GetWindowRect( hTask, &taskbar );

	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	window_width = desktop.right;
	window_height = desktop.bottom - ( taskbar.bottom - taskbar.top );

	resize_ratio = ceil( (double)img_size.width / window_width ) ;

	if ( resize_ratio < ceil( (double)img_size.height / window_height ) )

		resize_ratio = ceil( (double)img_size.height / window_height );

	return 1 / (double)( resize_ratio );
}

//! GetRect is a child function to annotateview
/*
The function will launch a tool where user will draw rectangles and the confirmed rectangles will be stored 
in the rect_list vector
/param cloneimg is the current cloned image of the original image 
/return The function returns the image after drawing rectangles on it 
and the same will be used to draw other objects on so that user 
always see the all objects he have drawn.
*/
Mat COutlook::GetRect( Mat cloneimg )
{
	Mat previmg = cloneimg.clone();
	color_count = 0;
	bool is_rect_drawn = true;
	do
	{
		imshow( "Interactive tool", cloneimg );
		if( false == is_rect_drawn )
		{
			if( IDYES == MessageBox( 0, L"You Have Completed the Rectangle.\n Do you want to Confirm the Rectangle", L"Confirm the Object", MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL ) )
			{
				CRectangle rect( points );
				rect_list.push_back( rect );
				previmg = cloneimg.clone();
				cout << "Object count   " << object_count << endl;
			}
			else
			{
				cloneimg = previmg.clone();
			}

			points.clear();
			is_rect_drawn = true;
		}
		cvSetMouseCallback( "Interactive tool", MouseCallbackFunction, 0 ); 	
		if( 2 == color_count )
		{
			line( cloneimg, points[0], points[1], g_COLORS[ object_count ], 4, 8, 0 );
		}
		if( 3 == color_count )
		{
			line( cloneimg, points[1], points[2], g_COLORS[ object_count ], 4, 8, 0 );
		}
		if( 4 == color_count )
		{
			line( cloneimg, points[2], points[3], g_COLORS[ object_count ], 4, 8, 0 );
			line( cloneimg, points[0], points[3], g_COLORS[ object_count ], 4, 8, 0 );
			is_rect_drawn = false;
			object_count = ( object_count + 1 ) % 10;      //only for different colors
			color_count = 0;
		}
		if( 27== waitKey(1) )
		{
			if( IDYES == MessageBox( 0, L"Are you sure you have drawn all the rectangles for this image ?", L"Really?", MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL ) )
			{
				points.clear();
				cloneimg = previmg.clone();
				break;
			}
		}
	}while(1);

	return cloneimg; 
}

//! GetLine is a child function to annotate view
/*
The function will launch a tool where user will draw two parallel lines and will be stored in line_list
The function uses same class CRectangle to store the line points. To recover the lines from the class
use get_hor_line(n) where n = 1 for first line and 2 for second.
/param cloneimg is the current cloned image of the original image 
/return The function returns the image after drawing two lines
and the same will be used to draw other objects on so that user 
always see the all objects he have drawn.
*/
Mat COutlook::GetLine( Mat cloneimg )
{
	Mat previmg = cloneimg.clone();
	color_count = 0;
	bool is_rect_drawn = true;
	do{
		imshow( "Interactive tool", cloneimg);
		if( false == is_rect_drawn )
		{
			if( IDYES == MessageBox( 0, L"You Have Drwan two parallel lines.\n Do you want to Confirm the lines ?", L"Confirm the Object", MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL ))
			{
				CRectangle rect(points);
				line_list.push_back(rect);
				previmg = cloneimg.clone();
				cout << "Object count   " << object_count << endl;
			}
			else
			{
				cloneimg = previmg.clone();
			}
			points.clear();
			is_rect_drawn = true;
		}
		cvSetMouseCallback( "Interactive tool", MouseCallbackFunction, 0 ); 
		if( 2 == color_count )
		{
			line( cloneimg, points[0], points[1], g_COLORS[ object_count ], 4, 8, 0 );
		}
		if( 4 == color_count )
		{
			line( cloneimg, points[2], points[3], g_COLORS[ object_count ], 4, 8, 0 );
			is_rect_drawn = false;
			object_count = ( object_count + 1 ) % 10;      //only for different colors
			color_count = 0;
		}
		if( 27 == waitKey(1) )
		{
			if(IDYES == MessageBox( 0, L"Are you sure you have drawn all the set of Parallel lines for this image ?", L"Really?", MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL))
			{
				points.clear();
				cloneimg = previmg.clone();
				break;
			}
		}
	}while(1);

	return cloneimg; 
}

//! FindPlaneNormals will find normals for all rectangles
/*
\param CamMat It is the camera Intrinsic Matrix (same for all panaromas)
*/
void COutlook::FindPlaneNormals( Mat CamMat )
{
	int no_of_rects = rect_list.size();
	Mat multiplier = rotation_mat.inv() * CamMat.inv();
	vector < Mat > hor_normals(2);
	vector < Mat > ver_normals(2); 

	for(int k = 0;k<no_of_rects;k++)
	{
		// step 1:Finding normal to the projection plane of lines 
		// For Horizontal lines

		for( int i = 0; i < 2; i++ )
		{
			vector <Point2f> hor_line = rect_list[k].GetHorLine( i % 2 + 1 );
			Mat pt1( 3, 1, CV_32FC1);
			Mat pt2( 3, 1, CV_32FC1);

			pt1.at <float> (0,0) = hor_line[0].x;
			pt1.at <float> (1,0) = hor_line[0].y;
			pt1.at <float> (2,0) = 1;
			pt2.at <float> (0,0) = hor_line[1].x;
			pt2.at <float> (1,0) = hor_line[1].y;
			pt2.at <float> (2,0) = 1;

			pt1 = multiplier * pt1 ;    //got the 3d point
			pt2 = multiplier * pt2 ;  

			hor_normals[i] = pt1.cross( pt2 );     
		}

		//finding vertical normals
		for( int i = 0; i < 2; i++ )
		{
			vector <Point2f> ver_line = rect_list[k].GetVerLine( i % 2 + 1 );
			Mat pt1( 3, 1, CV_32FC1 );
			Mat pt2( 3, 1, CV_32FC1 );

			pt1.at <float> (0,0) = ver_line[0].x;
			pt1.at <float> (1,0) = ver_line[0].y;
			pt1.at <float> (2,0) = 1;
			pt2.at <float> (0,0) = ver_line[1].x;
			pt2.at <float> (1,0) = ver_line[1].y;
			pt2.at <float> (2,0) = 1;

			pt1 = multiplier * pt1 ;    //got the 3d point
			pt2 = multiplier * pt2 ;  

			ver_normals[i] = pt1.cross( pt2 );
		}

		// finding the plane normal and pushing it back in the vector
		plane_normals.push_back( ( hor_normals[0].cross( hor_normals[1] ) ).cross( ver_normals[0].cross( ver_normals[1] ) ) );
	}

	logfile << " Plane Normals " << endl;
	for ( int i = 0 ; i < (int)plane_normals.size() ; i++ )
	{
		logfile << plane_normals[i].at <float> (0,0);
		logfile << plane_normals[i].at <float> (1,0);
		logfile << plane_normals[i].at <float> (2,0);
	}
}
