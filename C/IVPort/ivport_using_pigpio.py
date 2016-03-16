#!/usr/bin/python

import time
import picamera

import pigpio
import sys
import os

pigpio.exceptions = False
pi = pigpio.pi()

pi.set_mode(4, pigpio.OUTPUT)
pi.set_mode(17, pigpio.OUTPUT)
pi.set_mode(18, pigpio.OUTPUT)
cmdargs = str(sys.argv)
print 'Argument List:', str(sys.argv)


if str(sys.argv[1]) == '1':
    # CAM 1 for A Jumper Setting
    print(1)
    pi.write(4, 0)
    pi.write(17, 0)
    pi.write(18, 1)

elif str(sys.argv[1]) == '2':
    # CAM 2 for A Jumper Setting
    print(2)
    pi.write(4, 1)
    pi.write(17, 0)
    pi.write(18, 1)

if str(sys.argv[2]) == 'pic':
    os.system("raspistill -o cam.jpg")

elif str(sys.argv[2]) == 'vid':
    os.system("raspvid -o camTest1.mp4")


print('Saved...')
pi.stop()
