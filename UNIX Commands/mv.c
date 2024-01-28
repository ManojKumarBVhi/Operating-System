#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int input,output;
	
	if(argc != 3){
		printf("Insufficient Arguments");
		printf("Usage: mv filename pathname\n");
		
		return -1;
	}
	
	input = link(argv[1],argv[2]);
	if(input == -1){
		perror("Linking Error");
		
		return -1;
	}
	
	output = unlink(argv[1]);
	if(output == -1){
		perror("Unlinking error");
		return -1;
	}
	
	return 0;
}
