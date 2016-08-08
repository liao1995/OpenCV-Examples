/*
 * smooth.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: la
 */
#include "highgui.h"
#include "cv.h"

void smooth_demo(IplImage *image)
{
	// Create some windows to show the input
	// and output image in.
	cvNamedWindow( "Image-in" , CV_WINDOW_AUTOSIZE);
	cvNamedWindow( "Smooth-out", CV_WINDOW_AUTOSIZE);

	// Create a window to show our input image
	cvShowImage( "Image-in", image);

	// Create an image to hold the smoothed output
	IplImage* out = cvCreateImage(
			cvGetSize( image ),
			IPL_DEPTH_8U,
			3
	);

	// Do the smoothing
	cvSmooth( image, out, CV_GAUSSIAN, 3, 3 );

	// Show the smoothed image in the output window
	cvShowImage( "Smooth-out", out );

	// Be tidy
	cvReleaseImage( &out );

	// Wait for the user to hit a key, then clean up the windows
	cvWaitKey( 0 );
	cvDestroyWindow( "Image-in" );
	cvDestroyWindow( "Smooth-out" );
}


