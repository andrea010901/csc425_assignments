#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	printf("Process PID = %d\n", getpid());
	char* string = argv[1];
	int string_to_int = atoi(string);
	long long int bytes = (long long int)string_to_int * 1024 * 1024;
	long long int size = bytes;
	int* buffer = (int*)malloc(size);
	time_t duration;
	time_t end;
	time_t start;
	duration = atoi(argv[2]);
	start = time(NULL);
	end = start + duration;
	
	while(start<end){
	printf("running");
	for (long long int i=0; i < size / sizeof(int); i++) {
		buffer[i] = i;
	}
	start = time(NULL);
	}
	printf("program has finished");
	return 0;
} 
