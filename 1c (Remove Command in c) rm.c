#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char *argv[]){
	int del;
	if(argc < 2){
		printf("\n Insufficient Arguments");
		printf("\n Usage : rm filename\n");
	}
	del = unlink(argv[1]);
	if(del == -1){
		perror("usage error");
		return -1;
	}
	return 0;
}
