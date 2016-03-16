/*
Created by An on Mar. 12, 2016.
This program provides higher level of camera control.
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Taking Pictures.
void camPic5M(int camNumber, char *fileName);        // 2560x1920
void camPic4M(int camNumber, char *fileName);        // 2240x1680
void camPic3M(int camNumber, char *fileName);        // 2048x1536
void camPic2M(int camNumber, char *fileName);        // 1600x1200
void camPic1M(int camNumber, char *fileName);        // 1280x960
void camPic640x480(int camNumber, char *fileName);   // 640x480
void camPic320x240(int camNumber, char *fileName);   // 320x240

// Shooting Videos.
// 1920x1080
void camVid1080P(int camNumber, float time, int frameRate, char* fileName);
// 1280x720
void camVid720P(int camNumber, float time, int frameRate, char* fileName);
// 720x480
void camVid480P(int camNumber, float time, int frameRate, char* fileName);
// 1280x768
void camVidWXGA(int camNumber, float time, int frameRate, char* fileName);
// 800x600
void camVidSVGA(int camNumber, float time, int frameRate, char* fileName);
// 800x480
void camVidWVGA(int camNumber, float time, int frameRate, char* fileName);
// 640x480
void camVidVGA(int camNumber, float time, int frameRate, char* fileName);
// 320x240
void camVidQVGA(int camNumber, float time, int frameRate, char* fileName);

#endif //CAMERA_H
