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
const char* filename = "萧忆情Alex-红颜旧.mp4";

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(
			g_capture,
			CV_CAP_PROP_POS_FRAMES,
			pos
			);
}

void videoPlayer() {
	// filename = NULL;
	cvNamedWindow("Video Player", CV_WINDOW_AUTOSIZE);
	if (NULL != filename)
		g_capture = cvCreateFileCapture(filename);
	else
		g_capture = cvCreateCameraCapture(0); // read from camera

	if (NULL != filename) // slide bar for video file
			{
		int frames = (int) (cvGetCaptureProperty(g_capture,
				CV_CAP_PROP_FRAME_COUNT));
		if (frames > 0) {
			cvCreateTrackbar("Position", "Video Player", &g_slider_position,
					frames, onTrackbarSlide);
		}
	}
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(g_capture);
		if (!frame)
			break;

		cvShowImage("Video Player", frame);
		if (NULL != filename) {
			g_slider_position = cvGetCaptureProperty(g_capture,
					CV_CAP_PROP_POS_FRAMES);
			cvSetTrackbarPos("Position", "Video Player", g_slider_position);
		}
		char c = cvWaitKey(33);
		if (c == 27)
			break; // ESC
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Video Player");
}

void videoWriter()
{
	const char* outfile = "screencapture.avi";
	cvNamedWindow( "videoWriter" );
	CvCapture *capture = cvCreateCameraCapture( CV_CAP_ANY );
//	CvCapture *capture = cvCreateFileCapture(filename);
	assert( capture );
	IplImage *bgr_frame = cvQueryFrame( capture );
	double fps = cvGetCaptureProperty (
			capture,
			CV_CAP_PROP_FPS);
//	double fps = 30;
	CvSize size = cvSize(
			(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH ),
			(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT ));
	CvVideoWriter* writer = cvCreateVideoWriter(
			outfile,
			CV_FOURCC('M', 'J', 'P', 'G'),
			fps,
			size
			);
	IplImage* logpolar_frame = cvCreateImage(
			size,
			IPL_DEPTH_8U,
			3);
	while ( (bgr_frame=cvQueryFrame( capture )) != NULL ) {
		cvLogPolar( bgr_frame, logpolar_frame,
				cvPoint2D32f(bgr_frame->width/2, bgr_frame->height/2),
				40,
				CV_INTER_LINEAR+ CV_WARP_FILL_OUTLIERS );
//		cvWriteFrame( writer, logpolar_frame );
//		cvShowImage( "videoWriter", logpolar_frame );
		cvWriteFrame( writer, bgr_frame );
		cvShowImage( "videoWriter", bgr_frame );
		char c = cvWaitKey(33);
		if (c == 27)
			break; // ESC
	}
	cvReleaseVideoWriter( &writer );
	cvReleaseImage ( &logpolar_frame );
	cvReleaseCapture( &capture );
	cvDestroyWindow( "videoWriter" );
}

int main(int argc, char* argv[])
{
	// videoPlayer();
	videoWriter();
	return 0;
}


