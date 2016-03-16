#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("Program initialized!\n");
	printf("Let's take a picture now!\n");
	
	// Use command to capture a picture.
	system("raspistill -o ~/Pictures/camTest1.jpg");
	
	printf("And a video clip!\n");
	system("raspivid -o ~/Videos/camTest1.mp4");
	
	printf("All done. Have fun!\n");
	return 0;
}

