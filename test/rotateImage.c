#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <stdio.h>


#define PRINT_IMAGE_INFO 0		
#define DEGREES 60			
#define CV_WARP_FILL_OUTLIERS 8


void rotate(IplImage* _image, double ang)
{
	
	double _angle = DEGREES;
	CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
	CvPoint2D32f center = cvPoint2D32f(_image->width / 2, _image->height / 2);
	double angle = ang;
	double scale = 1;
	cv2DRotationMatrix(center, angle, scale, rot_mat);

	IplImage* Temp = 0;
	Temp = cvCreateImage(cvSize(_image->width, _image->height), _image->depth, _image->nChannels);
	cvWarpAffine(_image, Temp, rot_mat, CV_WARP_FILL_OUTLIERS, CV_RGB(255, 255, 255));


	cvCopy(Temp, _image, NULL);

	cvReleaseImage(&Temp);
	cvReleaseMat(&rot_mat);
}

int main(int argc, char* argv[])
{
	IplImage* image = 0;
	IplImage* src = 0;
	char* filename = argc == 2 ? argv[1] : "test.jpg";
	image = cvLoadImage(filename, 1);
	src = cvCloneImage(image);

	printf("[i] image: %s\n", filename);
	assert(src != 0);
	cvNamedWindow("Picture", CV_WINDOW_AUTOSIZE);
	
	rotate(image, DEGREES);

	cvShowImage("Picture", image);

	if (PRINT_IMAGE_INFO)
	{
		
		printf("[i] channels:  %d\n", image->nChannels);
		printf("[i] pixel depth: %d bits\n", image->depth);
		printf("[i] width:       %d pixels\n", image->width);
		printf("[i] height:      %d pixels\n", image->height);
		printf("[i] image size:  %d bytes\n", image->imageSize);
		printf("[i] width step:  %d bytes\n", image->widthStep);
	}

	cvWaitKey(0);

	cvReleaseImage(&image);
	cvReleaseImage(&src);
	cvDestroyWindow("Picture");
	return 0;
}
