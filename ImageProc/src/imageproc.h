/*
 * imageproc.h
 *
 *  Created on: Aug 8, 2016
 *      Author: la
 */

#ifndef IMAGEPROC_H_
#define IMAGEPROC_H_

void smooth_demo( IplImage* );
IplImage* doPyrDown ( IplImage* ,
		int filter = IPL_GAUSSIAN_5x5 );
IplImage* doCanny( IplImage* in,
		double lowThresh,
		double highThresh,
		double aperture);

#endif /* IMAGEPROC_H_ */
