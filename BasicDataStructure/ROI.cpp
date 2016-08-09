/*
 * ROI.cpp
 *
 *  Created on: Aug 10, 2016
 *      Author: la
 */

#include "cv.h"
#include "highgui.h"

void setROI(IplImage* src, CvRect rect, int add)
{
	cvSetImageROI( src, rect );
	cvAddS( src, cvScalar(add), src );
	cvResetImageROI( src );
}

void ROI_demo()
{
	const char* filename = "corji.jpg";
	IplImage* image = cvLoadImage( filename );
	assert( image );
	setROI( image, cvRect(115, 40, 300, 255), 100 );
	cvNamedWindow( "ROI" );
	cvShowImage( "ROI", image );
	cvReleaseImage( &image );
	cvWaitKey( 0 );
	cvDestroyWindow( "ROI" );
}

int main( int argc, char* argv[] )
{
	ROI_demo();
	return 0;
}
