
/*
   CvCapture -> RaspiCamCvCapture
   cvCreateCameraCapture -> raspiCamCvCreateCameraCapture
   cvQueryFrame -> raspiCamCvQueryFrame
   cvReleaseCapture -> raspiCamCvReleaseCapture
   cvGetCaptureProperty -> raspiCamCvGetCaptureProperty
 */
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <typeinfo>

#include "RaspiCamCV.h"

using namespace std;
using namespace cv;

int main( int argc, const char** argv )
{

	//CvCapture* capture = 0;
	RaspiCamCvCapture* capture = 0;

	RASPIVID_CONFIG * config = (RASPIVID_CONFIG*)malloc(sizeof(RASPIVID_CONFIG));
	//config->width=320;
	//config->height=240;
	config->width=640;
	config->height=480;
	config->bitrate=17000000;
	config->framerate=2;
	config->monochrome=0;

	// save 
	//VideoWriter writer("result.avi",CV_FOURCC_DEFAULT,10,Size(640,480),true);

	// --------------------------------------------------------------
	cv::Mat frame1,grayImage;

	// catch raspi-cam
	capture = (RaspiCamCvCapture *) raspiCamCvCreateCameraCapture2(0, config); 

	//cvNamedWindow( "raspi-cam", 1 );

	//cvSetMouseCallback("raspi-cam",on_mouse,0);
	if( capture ){
		char fname[256];
		char cmd[256];
		char cmd2[256];

			//IplImage* iplImg = cvQueryFrame( capture );
			IplImage* iplImg1;
			iplImg1 = raspiCamCvQueryFrame( capture );
			frame1 = iplImg1;
			// optimize frame
			cv::flip(frame1,frame1,0);
			cv::flip(frame1,frame1,1);

			// display Image
			//cv::imshow("raspi-cam", frame1);

			//sprintf(fname,"raspi-cam.jpg");
			sprintf(cmd,"echo \"./img/raspi-cam.jpg?%d\">imgName.txt",time(NULL));
			sleep(0);
			cv::imwrite("raspi-cam.jpg",frame1);
			system(cmd);
			

_cleanup_:

	//	cvReleaseCapture( &capture );
		// change for raspicam
		raspiCamCvReleaseCapture(&capture);
	}
	//cvDestroyWindow("raspi-cam");

	return 0;
}

