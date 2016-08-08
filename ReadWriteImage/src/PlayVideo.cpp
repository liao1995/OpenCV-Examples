/*
 * PlayVideo.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: la
 */

#include "highgui.h"
#include "cv.h"

int				g_slider_position 	= 0;
CvCapture*		g_capture			= NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(
			g_capture,
			CV_CAP_PROP_POS_FRAMES,
			pos
			);
}
int main(int argc, char* argv[])
{
	const char *filename = "萧忆情Alex-红颜旧.mp4";
	// filename = NULL;
	cvNamedWindow( "Video Player", CV_WINDOW_AUTOSIZE);
	if ( NULL != filename )
		g_capture = cvCreateFileCapture( filename );
	else
		g_capture = cvCreateCameraCapture( 0 );	// read from camera

	if ( NULL != filename )	// slide bar for video file
	{
		int frames = (int) cvGetCaptureProperty(
				g_capture,
				CV_CAP_PROP_FRAME_COUNT);
		if ( frames > 0 )
		{
			cvCreateTrackbar(
					"Position",
					"Video Player",
					& g_slider_position,
					frames,
					onTrackbarSlide);
		}
	}
	IplImage * frame;
	while (1)
	{
		frame = cvQueryFrame( g_capture );
		if ( !frame ) break;
		cvShowImage ( "Video Player", frame );
		if ( NULL != filename )
		{
			g_slider_position = cvGetCaptureProperty(
					g_capture,
					CV_CAP_PROP_POS_FRAMES);
			cvSetTrackbarPos(
					"Position",
					"Video Player",
					g_slider_position);
		}
		char c = cvWaitKey(33);
		if ( c == 27 ) break;	// ESC
	}
	cvReleaseCapture( &g_capture );
	cvDestroyWindow( "Video Player" );
	return 0;
}


