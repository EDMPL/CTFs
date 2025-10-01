#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32];
int main(int argc, char* argv[], char* envp[]){
	if(argc<2){
		printf("pass argv[1] a number\n");
		return 0;
	}
	int fd = atoi( argv[1] ) - 0x1234;
	int len = 0;
    printf("fd: %d\n", fd); // Check fd
	if(!strcmp("LETMEWIN\n", buf)){
		printf("good job :)\n");
		exit(0);
	}
	printf("learn about Linux file IO\n");
	return 0;

}
