/*
 * main.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: la
 */

#include "highgui.h"
#include "cv.h"
#include "imageproc.h"

const char *filename = "corji.jpg";

void doPyrDown_demo() {
	// smooth_demo( image );
	IplImage* image = cvLoadImage(filename);
	assert(image != NULL);
	cvNamedWindow("Show");
	IplImage* out = doPyrDown( image );
	cvShowImage("Show", out );
	cvReleaseImage(&out);
	cvWaitKey(0);
	cvDestroyWindow("Show");
}

void doCanny_demo()
{
	IplImage* image = cvLoadImage( filename, CV_LOAD_IMAGE_GRAYSCALE );
	assert ( NULL != image );
	cvNamedWindow ( "Canny" );
	IplImage* out = doCanny( image, 10, 100, 3 );
	cvShowImage( "Canny", out );
	cvWaitKey( 0 );
	cvReleaseImage( &out );
	cvDestroyWindow( "Canny" );
}

void doPyrDownAndCanny_demo()
{
	IplImage* image = cvLoadImage( filename, CV_LOAD_IMAGE_GRAYSCALE );
	assert ( NULL != image );
	cvNamedWindow( "PyrDownCanny" );
	IplImage* out = doPyrDown( image );	// release image in function
	out = doPyrDown ( out );	// must release input image in function can do this
	out = doPyrDown ( out );
	out = doCanny( out, 10, 100, 3 );
	cvShowImage( "PyrDownCanny", out );
	cvReleaseImage( &out );
	cvWaitKey( 0 );
	cvDestroyWindow( "PyrDownCanny" );
}

int main (int argc, char *argv[])
{
	// smooth_demo( image );
	// doPyrDown_demo();
	// doCanny_demo();
	// doPyrDownAndCanny_demo();
	alpha_blend_demo();
	return 0;
}


