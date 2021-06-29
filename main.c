
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "branch_1.c"
#include "crazy_1.c"





double getCurrentTime();
double timeSince(double past);


int main(int argc, char* argv[]) {
	double start;
	char buffer[1024];
	int loops = 10000;
	
	for(int i = 0; i < 10000; i++) {
	//	naive_1(100, buffer);
	}
	start = getCurrentTime();
	for(int i = 0; i < loops; i++) {
	//	naive_1(100, buffer);
	}
	double n1time = timeSince(start);
	
	for(int i = 0; i < 10000; i++) {
		buffered_1(100, buffer);
	}
	start = getCurrentTime();
	for(int i = 0; i < loops; i++) {
		buffered_1(100, buffer);
	}
	double f1time = timeSince(start);
	
	
	for(int i = 0; i < 10000; i++) {
		crazy_1(100, buffer);
	}
	start = getCurrentTime();
	for(int i = 0; i < loops; i++) {
		crazy_1(100, buffer);
	}
	double o1time = timeSince(start);
	
	
	
	
	for(int i = 0; i < 10000; i++) {
		branch_1(100, buffer);
	}
	start = getCurrentTime();
	for(int i = 0; i < loops; i++) {
		branch_1(100, buffer);
	}
	double b1time = timeSince(start);
	
	printf("\n\n\n");
	printf("naive: %f\n", n1time* 1000);
	printf("buffered: %f\n", f1time* 1000);
	printf("branch: %f\n", b1time* 1000);
	printf("crazy: %f (%.3f%% slower)\n", o1time* 1000, -((b1time - o1time) * 100) / b1time);
	
	return 0;
}





double getCurrentTime() { // in seconds
	double now;
	struct timespec ts;
	
	// CLOCK_MONOTONIC_RAW is linux-specific.
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	
	now = (double)ts.tv_sec + ((double)ts.tv_nsec / 1000000000.0);
	
	return now;
}

double timeSince(double past) {
	double now = getCurrentTime();
	return now - past;
}

