/*
 * main.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: la
 */

#include "highgui.h"
#include "cv.h"
#include <stdio.h>
#include <string.h>
#define MAXFILENAMELEN 256

int _main(int argc, char *argv[])
{
	char path[MAXFILENAMELEN];
	IplImage* img;
	printf( "Please enter the path of image file: \n");
	fgets(path, MAXFILENAMELEN-1, stdin);
	path[strlen(path)-1] = '\0'; // remove new line character
	img = cvLoadImage( path );
	if (img == NULL)
		fprintf(stderr, "Can not read the image file %s!\n", path);
	else
	{
		cvNamedWindow( "Example 1", CV_WINDOW_AUTOSIZE);
		cvShowImage ("Example 1", img);
		cvWaitKey(0);
		cvReleaseImage( &img );
		cvDestroyWindow( "Example 1" );
	}
	return 0;
}


