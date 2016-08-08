/*
 * canny.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: la
 */

#include "cv.h"

IplImage* doCanny( IplImage* in,
		double lowThresh,
		double highThresh,
		double aperture)
{
	if ( in->nChannels != 1)
		return NULL;	// Canny only handles gray scale images

	IplImage* out = cvCreateImage(
			cvSize( in->width, in->height ),
			IPL_DEPTH_8U,
			1);
	cvCanny( in, out, lowThresh, highThresh, aperture );
	cvReleaseImage( &in );
	return out;
}


