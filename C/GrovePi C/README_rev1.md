===============Revision History====================
Rev. 1:
Mar. 10, 2016   File created by An. Reviewed By Alaa.

================Accessing pin=====================
Set the mode of a pin (1: output, 0: input):
    int pinMode(int pin,int mode)

Write a digital value to a pin (value is 0 or 1):
    int digitalWrite(int pin,int value)

Read a digital value from a pin (return value is 0 or 1):
    int digitalRead(int pin)

Read an analog value from a pin:
    int analogRead(int pin)

Write a PWM value to a pin:
    int analogWrite(int pin,int value)

Read ultrasonic value from a pin:
    int ultrasonicRead(int pin)

======================Delay=====================
Delay time t (in seconds):
    void pi_sleep(int t)

Or generic gcc delay function (in mili-seconds):
    void usleep(int t)

