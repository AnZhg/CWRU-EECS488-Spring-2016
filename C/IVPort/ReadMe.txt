Include <pigpio.h> in your source files. 

Assuming your source is in prog.c use the following command to build and run the executable. 

gcc -Wall -pthread -o prog prog.c -lpigpio -lrt
./prog