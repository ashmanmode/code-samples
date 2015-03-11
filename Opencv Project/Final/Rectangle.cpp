#include "Rectangle.h"

using namespace cv;
using namespace std;

//! Constructor of the class
/*
	  \param vertices is a vector of 4 Point2f points corresponding to a rectangle
*/
CRectangle::CRectangle( vector < Point2f > vertices )
{
	a = vertices[0];
	b = vertices[1];
	c = vertices[2];
	d = vertices[3];
}

//! GetVerLine gives the vector of points for vertical line
/*
	  \return Vector of 2 points of end points of the line
	  \param n is the no. of line ( put 1 for first line and 2 for second )
*/
vector < Point2f > CRectangle::GetVerLine( int n )
{
	std::vector < cv::Point2f > line(2);
	if( 1 == n )
	{
		line[0] = a;
		line[1] = d;
	}
	else if( 2 == n )
	{
		line[0] = b;
		line[1] = c;
	}
	return line;
}

//! GetHorLine gives the vector of points for horizontal line
/*
	  \return Vector of 2 points of end points of the line
	  \param n is the no. of line ( put 1 for first line and 2 for second )
*/
vector < Point2f > CRectangle::GetHorLine( int n )
{
	std::vector < cv::Point2f > line(2);
	if( 1 == n )
	{
		line[0] = a;
		line[1] = b;
	}
	else if( 2 == n )
	{
		line[0] = c;
		line[1] = d;
	}
	return line;
}

//! GetRectangle gives the vector of 4 points for the rectangle
/*
	  \return Vector of 4 points of rectangle of type Point2f
*/
vector < Point2f > CRectangle::GetRectangle()
{
	std::vector < cv::Point2f > rect(4);
	rect[0] = a;
	rect[1] = b;
	rect[2] = c;
	rect[3] = d;
	return rect;
}

//! GetPoint gives the points 
/*
	  \return point of rectangle of type Point2f
	  \param n is the no. of point ( 1, 2, 3, 4 in anti-clockwise direction )
*/
Point2f CRectangle::GetPoint(int n)
{
	cv::Point2f pt;
	switch (n)
	{
	case 1:
		pt = a;
		break;
	case 2:
		pt = b;
		break;
	case 3:
		pt = c;
		break;
	case 4:
		pt = d;
		break;
	}
	return pt;
}