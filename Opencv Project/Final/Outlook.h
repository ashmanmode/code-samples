#pragma once
#include "Header.h"
#include "Rectangle.h"

class COutlook
{
public:
	/*! SetImage will take Mat file as input image and store in COutlook class */
	void SetImage( cv::Mat );		
	/*! FindRotationWithHomography will take intrinsic Camera Matrix as input ,then find and store in RotationMat */
	void FindRotationWithHomography( cv::Mat , COutlook* );
	/*! AnnotateView will collect all the rects and store in class */
	void AnnotateView();
	/*! FindPlaneNormals will find normals for all rectangles */
	void FindPlaneNormals( cv::Mat );

private:
	// Variable Declarations
	cv::Mat original_image;
	cv::Mat rotation_mat;
	std::vector < CRectangle > rect_list; // RectList or rect_list
	std::vector < CRectangle > line_list;
	std::vector < cv::Mat > plane_normals;

	//functions
	/*! GetRect is a child function to AnnotateView */
	cv::Mat GetRect( cv::Mat );
	/*! GetLine is a child function to AnnotateView */
	cv::Mat GetLine( cv::Mat );
};

