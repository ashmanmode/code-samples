#include "Panorama.h"

using namespace std;
using namespace cv;

extern ofstream logfile;

//! LoadView will take the input file and load all images to view_list  
/*
	  \param filename The input filename containing image names
	  \sa    ReadMe-> input file format
*/
int CPanorama::LoadViews( char* filename )
{
	ifstream input_file;
    string line;
    input_file.open( filename );                                               //opening the text file

	if ( input_file.fail() )                                   
    {
		cerr << "Error Opening File, check filename again" << endl;            //error reporting   
		return -1;
    }

    if ( input_file.is_open() )                                                //reading filenames from the text file and then loading image from the name
    {
        while( getline( input_file,line ) )
        {
			Mat input_img = imread( line );
			COutlook img_view;
			if( input_img.empty() )
			{
				cerr << " Error opening the Image File " << endl;
				logfile << " File named " << line << "was not loaded" << endl;
			}
			img_view.SetImage( input_img );
			view_list.push_back( img_view );
			//counter_images++;
        }
        input_file.close();
    }
	
	return 0;
}

//! CollectData will collect all the data pertainng to an image and stores in view_list 
/*
	  This will launch the Interactive tool and take all user input and then 
	  find the Rotation Matrix , Plane Normals to all Rectangles
	  \param CamMat It is the camera Intrinsic Matrix (same for all panaromas)
*/
int CPanorama::CollectData( const Mat &CamMat )
{
	// For first image we assume the rotation so
	view_list[0].FindRotationWithHomography( CamMat, NULL );
	view_list[0].AnnotateView();

	for( int i = 1; i < (int) view_list.size(); i++ )
	{
		view_list[i].FindRotationWithHomography( CamMat, &view_list[ i - 1 ] );
		view_list[i].AnnotateView();
		view_list[i].FindPlaneNormals( CamMat );
	}

	return 0;
}





