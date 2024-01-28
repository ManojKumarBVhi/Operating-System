#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]){
	int src,dest;
	char buff[BUFF_SIZE];
	ssize_t bytesRead, bytesWritten;
	if(argc != 3){
		printf("\n Insuffienct Arguments");
		printf("\n Usage : cp source_file destination_file");
	}
	src = open(argv[1], O_RDONLY);
	if(src == -1){
		perror("\n Error opening the file");
		return -1;
	}
	
	dest = open(argv[2], O_WRONLY | O_CREAT,0644);
	if(dest == -1){
		perror("Error writing the file");
		close(src);
		return -1;
	}
	
	while((bytesRead = read(src,buff,BUFF_SIZE)) > 0){
		bytesWritten = write(dest,buff,bytesRead);
		if(bytesRead != bytesWritten){
			perror("Error writing the file");
			close(src);
			close(dest);
			return -1;
		}
	}
	
	close(src);
	close(dest);
	
	return 0;
}	
