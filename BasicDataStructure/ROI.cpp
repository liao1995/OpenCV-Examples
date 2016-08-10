/*
 * ROI.cpp
 *
 *  Created on: Aug 10, 2016
 *      Author: la
 */

#include "cv.h"
#include "highgui.h"

const char* filename = "corji.jpg";

void setROI(IplImage* src, CvRect rect, int add)
{
	cvSetImageROI( src, rect );
	cvAddS( src, cvScalar(add), src );
	cvResetImageROI( src );
}

void ROIImage_demo()
{
	IplImage* image = cvLoadImage( filename );
	assert( image );
	CvRect roi_rect = cvRect(115, 40, 300, 255);
	IplImage* roi_img = cvCreateImageHeader (
		cvSize(roi_rect.width, roi_rect.height)	,
		image->depth,
		image->nChannels
		);
	roi_img->widthStep = image->widthStep;
	roi_img->origin = image->origin;
	roi_img->imageData = image->imageData +
			roi_rect.y * image->widthStep +
			roi_rect.x * image->nChannels;
	cvNamedWindow( "ROI_SUB" );
	cvAddS( roi_img, cvScalar(100), roi_img );
	cvReleaseImageHeader( &roi_img );
	cvShowImage( "ROI_SUB", image );
	cvReleaseImage( &image );
	cvWaitKey( 0 );
	cvDestroyWindow( "ROI_SUB" );
}
void ROI_demo()
{
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
//	ROI_demo();
	ROIImage_demo();
	return 0;
}
