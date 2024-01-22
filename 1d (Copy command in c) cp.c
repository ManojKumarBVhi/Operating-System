#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFF_SIZE 2048 //we'll read and write 2048 bytes at a time

int main(int argc, char *argv[]){
  int src,dest;
  char buff[BUFF_SIZE];
  ssize_t bytesRead, bytesWritten;

  if(argc != 3){
    printf("\n Insufficient Arguments");
    printf("\n Usage: cp source_file destination_file);
  }

  src = open(argv[1], O_RDONLY);
  if(src == -1){
    perror("Error reading the file");
    return -1;
  }

  dest = open(argv[2].O_WRONLY | O_CREAT, 0644); //O_CREAT is the file doesn't exist and 0644 is the setting permission.
  if(dest == -1){
    perror("Error writing file");
    close(src);
    return -1;
  }

  while((bytesRead = read(src,buff,BUFF_SIZE) > 0){
    bytesWritten = write(dest, buff, bytesRead);
    if(bytesRead != bytesWritten){
      perror("Error in writing file");
      close(src);
      close(dest);
      return -1;
    }
  }
    
  close(src);
  close(dest);

  return 0;
}
