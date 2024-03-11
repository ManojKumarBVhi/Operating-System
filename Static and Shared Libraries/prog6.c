/* add.c
  int add(int a, int b){
    return a+b;
}
sub.c
int sub(int a, int b){
    return a-b;
mul.c
int mul(int a, int b){
    return a*b;
div.c
int div(int a, int b){
    return a/b;

main.c
#include<stdio.h>
#include"add.c"
#include"sub.c"
#include"mul.c"
#include"div.c"

int main(){
  printf("Addition : %d",add(2,2));
  printf("Subtraction : %d",sub(6,2));
  printf("Multiplication : %d",mul(2,2));
  printf("Division : %d",div(8,4));

  return 0;
}
For STATIC Library RUN these commands
cc -c *.c (it creates the object file for all .c files)
rm main.o
ar cr *.o mylib.a (Archiving all the .o files to one file mylib.a)
ar -t mylib.a (display the content of mylib.a)
cc -o static main.c mylib.a (Renaming the executable file name from a.out to static)
./static



For DYNAMIC Library RUN these commands
cc -fPIC -c *.c
rm main.o
cc -shared -o mylib.so *.o
sudo cp mylib.so /usr/bin
cc main.c -L. -l:mylib.so -o dynamic
./dynamic
