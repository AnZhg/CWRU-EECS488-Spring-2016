/*
Port from python code. (By An on Mar. 11, 2016)

To compile:
    $ gcc -Wall -o test IVPortGenericC.c -lwiringPi

==============================================================
How to select camera:
___________________________________
     \Pin #  |  17  |  18  |   4
camera\      |      |      |
-------------+------+------+-------
  camera  1  |   0  |   1  |   0
  camera  2  |   0  |   1  |   1
  camera  3  |   1  |   0  |   0
  camera  4  |   1  |   0  |   1
  no camera  |   1  |   1  |   X
___________________________________
==============================================================
Ivport is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

void capture(int cam);

int main(int argc, const char* argv[])
{
    // Get permission to write/read pin without sudo.
    system("gpio export 17 out");    // Enable 1
    system("gpio export 18 out");    // Enable 2
    system("gpio export  4 out");    // Selection

    // Initialize wiringPi.
    wiringPiSetupSys();

    // Configure pin mode.
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(4, OUTPUT);

    // Capture image from camera 1.
    digitalWrite(17,  LOW);
    digitalWrite(18, HIGH);
    digitalWrite(4,  LOW);
    capture(1);

    // Capture image from camera 2.
    digitalWrite(17,  LOW);
    digitalWrite(18, HIGH);
    digitalWrite(4, HIGH);
    capture(2);

    /*// Capture image from camera 3.
    digitalWrite(17,  HIGH);
    digitalWrite(18, LOW);
    digitalWrite(4,  LOW);
    capture(3);

    // Capture image from camera 4.
    digitalWrite(17,  HIGH);
    digitalWrite(18, LOW);
    digitalWrite(4,  HIGH);
    capture(4);*/

    return 0;
}

void capture(int cam)
{
    char cmd[33];
    sprintf(cmd, "raspistill -o capture_%d.jpg -t 1", cam);
    system(cmd);
}
