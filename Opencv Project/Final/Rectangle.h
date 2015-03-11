#pragma once
#include"Header.h"

class CRectangle
{
	public:
		/*! Constructor for the class ( Takes vector of 4 points as input ) */
		CRectangle( std::vector < cv::Point2f > vertices );  
		/*! GetVerLine gives the vector of points for vertical line ( n = 1, 2 for two lines ) */
		std::vector < cv::Point2f > GetVerLine( int n );     
		/*! GetHorLine gives the vector of points for horizontal line ( n = 1, 2 for two lines ) */
		std::vector < cv::Point2f > GetHorLine( int n );          
		/*! GetRectangle gives the vector of 4 points for the rectangle */ 
		std::vector < cv::Point2f > GetRectangle(); 
		/*! GetPoint gives the points ( n = 1, 2, 3, 4 for four points ) */ 
		cv::Point2f GetPoint( int n );                                                 
	private:
		// a = top left, points in CW order
		cv::Point2f a, b, c, d;
};

