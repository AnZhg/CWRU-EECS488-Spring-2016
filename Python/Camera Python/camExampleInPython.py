import picamera
from time import sleep

camera = picamera.PiCamera()

print "Program initialized."
print "Let's take a picture!"
camera.capture('camTest2.jpg')
print "Let's take a video then."
camera.start_recording('camTest2.h264')
sleep(5)
camera.stop_recording()
print "All done. Have fun!"

