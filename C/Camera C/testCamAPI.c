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
	camVid1080P(1, 3, 30, "CAM1_1080P.h264");
	camVidQVGA(2, 9.6, 20, NULL);
	return 0;
}
