/*
This is a test file for using camera API.
Created by An on Mar. 12, 2016

How to compile:
	$ gcc -Wall -o testCamAPI camera.c testCamAPI.c -lwiringPi
*/

#include <stdio.h>
#include "camera.h"

int main(int argc, const char *argv[])
{
	camPic5M(1, NULL);
	camPic2M(2, "CAM2_2M.jpg");
	camPic320x240(3, "CAM3_Low.jpg");
    camPic1M(4, "CAM4_Mid.jpg");
    camVid1080P(1, 3, 30, "CAM1_1080P.h264");
	camVidQVGA(2, 9.6, 20, NULL);
	camVid720P(3, 10, 5, "CAM3_720P.h264");
    camVid480P(4, 10, 10, "CAM4_480P.h264");
    return 0;
}
