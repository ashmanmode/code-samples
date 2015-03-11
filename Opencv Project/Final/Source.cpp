#include "Header.h"
#include "Rectangle.h"
#include "Outlook.h"
#include "Panorama.h"

using namespace cv;
using namespace std;

ofstream logfile("logfile.txt");

void WelcomeMessage()
{
	if( IDNO == MessageBox( 0, L"Welcome to the Interactive 3D constructor \n Are you sure You want to proceed ? ", L"Welcome", MB_YESNO ))
	{
		exit(0);
	}
}

int main( int argc, char *argv[] )
{
	WelcomeMessage();
	Mat CamMat;
	FileStorage cam_file( "CamMat.xml", FileStorage::READ );
	cam_file[ "CamMat" ] >> CamMat;
	if( CamMat.empty() )
	{
		cerr << "Error Loading the Camera Matrix" << endl;
		return -1;
	}

	CPanorama pan;
	if ( 0 == pan.LoadViews( "input_images.txt" ) )
	{
		pan.CollectData( CamMat );
	}

	return 0;
}

