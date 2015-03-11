#pragma once
#include "Header.h"
#include "Outlook.h"

class CPanorama
{
	public:
		/*! LoadViews will take the input file and load all images to view_list  */
		int LoadViews( char* filename );
		/*! CollectData will collect all the user data pertainng to all images and store in view_list */
		int CollectData( const cv::Mat &CamMat );

	private:
		std::vector < COutlook > view_list;
};
