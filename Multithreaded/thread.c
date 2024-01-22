#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int i;

void *print(void *i){
	int *j = (int *)i;
	printf("Thread number %d\n",*j);
}

int main(){
	pthread_t tid[3];
	for(i=0; i<3; i++){
		pthread_create(&tid[i], NULL, print, (void *)&i);
		sleep(1);
	}
	for(i=0; i<3; i++){
		pthread_join(tid[i], NULL);
	}
	
	return 0;
}

/*

Application

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define SIZE 4

int array1[SIZE] = [1,2,3,4];
int array2[SIZE] = [5,6,7,8];

int sumArray[SIZE];

void *addArray(void *arg){
	int index = *(int *)arg;
	sumArray[index] = array1[index] + array2[index];
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[SIZE];
	int i;
	for(i=0; i<SIZE; i++){
		pthread_create(&threads[i], NULL, addArray, (void *)&i);
		sleep(1);
	}
	for(i=0; i<SIZE; i++){
		pthread_join(threads[i],NULL);
	}
	for(i=0; i<SIZE; i++){
		printf("Sum of elements at %d is %d\n",i,sumArra[i]);
	}

	return 0;
}
*/
