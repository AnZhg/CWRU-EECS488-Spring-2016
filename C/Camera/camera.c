/*
Create by An on Mar. 12, 2016
*/
#include "camera.h"
#include <wiringPi.h>

char *_fileName;

void initCam(int camNumber, char *fileName, int mode) // mode: 0, Pic; 1, Vid.
{
	// Set file extension.
	char *extension = malloc(sizeof(char) * 6);
	strcpy(extension, mode ? ".h264" : ".jpg");
	extension[strlen(extension)] = '\0';

	// Set file name.
	_fileName = malloc(sizeof(char) * 80);
    if(fileName == NULL) {
        time_t now = time(NULL);
        strftime(_fileName, 19, "%04Y%02m%02d%02H%02M%02S", localtime(&now));
		strcat(_fileName, extension);
    } else {
        strcpy(_fileName, fileName);
    }

	// Dealloc memory.
	free(extension);

	// Set pin.
	static int state = -1;
	if(state) {
    	// Get permission to write/read pin without sudo.
    	system("gpio export 17 out");    // Enable 1
    	system("gpio export 18 out");    // Enable 2
    	system("gpio export  4 out");    // Selection

    	// Initialize wiringPi.
    	state = wiringPiSetupSys();

    	// Configure pin mode.
    	pinMode(17, OUTPUT);
    	pinMode(18, OUTPUT);
    	pinMode(4, OUTPUT);
	}

    switch(camNumber) {
        case 1:
            digitalWrite(17, 0);
            digitalWrite(18, 1);
            digitalWrite( 4, 0);
            break;
        case 2:
            digitalWrite(17, 0);
            digitalWrite(18, 1);
            digitalWrite( 4, 1);
            break;
        case 3:
            digitalWrite(17, 1);
            digitalWrite(18, 0);
            digitalWrite( 4, 0);
            break;
        case 4:
            digitalWrite(17, 1);
            digitalWrite(18, 0);
            digitalWrite( 4, 1);
            break;
        default: break;
    }
}

// Take picture.
void camPic5M(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 2560 -h 1920 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic4M(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 2240 -h 1680 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic3M(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 2048 -h 1536 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic2M(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 1600 -h 1200 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic1M(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 1280 -h 960 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic640x480(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 640 -h 480 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camPic320x240(int camNumber, char *fileName)
{
    char cmd[160] = "raspistill -w 320 -h 240 -t 1 -o ";
	initCam(camNumber, fileName, 0);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

// Shooting Videos.
void camVid1080P(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 1920 -h 1080 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVid720P(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 1280 -h 720 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVid480P(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 720 -h 480 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVidWXGA(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 1280 -h 768 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVidSVGA(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 800 -h 600 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVidWVGA(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 800 -h 480 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVidVGA(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 640 -h 480 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}

void camVidQVGA(int camNumber, float time, int frameRate, char* fileName)
{
	char cmd[160] = "raspivid -w 320 -h 240 ";
	int _time = time > 0 ? (time * 1000) : 10000;  // Default record time 10 seconds.
	char buf[10];
	sprintf(buf, "-t %d ", _time);
	strcat(cmd, buf);
	int _frameRate = ((frameRate > 1) && (frameRate <= 30)) ? frameRate : 30;	// Default frame rate is 30 fps.
	sprintf(buf, "-fps %d -o ", _frameRate);
	strcat(cmd, buf);
	initCam(camNumber, fileName, 1);
    strcat(cmd, _fileName);
	// Dealloc memory.
	free(_fileName);
    system(cmd);
}
