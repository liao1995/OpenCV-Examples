/*
 * alphablend_demo.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: la
 */
#include <cv.h>
#include <highgui.h>

const char* file1 = "corji.jpg";
const char* file2 = "star.png";

void alpha_blend(IplImage* src1, IplImage* src2,
		int x, int y, int width, int height,
		double alpha, double beta)
{
	cvSetImageROI( src1, cvRect( x, y, width, height ) );
	cvSetImageROI( src2, cvRect( x, y, width, height ) );
	cvAddWeighted( src1, alpha, src2, beta, 0.0, src1 );
}

void alpha_blend_demo()
{
	IplImage* src1 = cvLoadImage( file1 );
	IplImage* src2 = cvLoadImage( file2 );
	assert( src1 && src2 );
	cvNamedWindow( "Image 1" );
	cvShowImage( "Image 1", src1 );
	cvNamedWindow( "Image 2" );
	cvShowImage( "Image 2", src2 );
	alpha_blend(src1, src2, 0, 0, 512, 512, 0.7, 0.3);
	cvNamedWindow( "Blend" );
	cvShowImage( "Blend", src1 );
	cvWaitKey( 0 );
	cvDestroyWindow( "Blend" );
	cvDestroyWindow( "Image 2" );
	cvDestroyWindow( "Image 1" );
	cvReleaseImage( &src1 );
	cvReleaseImage( &src2 );
}

