#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int count = 0, readcount = 0;
sem_t mutex,wrt;

void *writer(void *args){
	int *i = (void *)args;
	sem_wait(&wrt);
	printf("\n Writer %d write %d",*i,++count);
	sem_post(&wrt);
}

void *reader(void *args){
	int *i = (int *)args;
	sem_wait(&mutex);
	readcount++;
	if(readcount == 1)
		sem_wait(&wrt);
	sem_post(&mutex);
	printf("\n Reader %d read %d",*i,count--);
	sem_wait(&mutex);
	readcount--;
	if(readcount == 0)
		sem_post(&wrt);
	sem_post(&mutex);
}

int main(){
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	int i;
	int a[6] = {1,2,3,1,2,3};
	pthread_t wr[6];
	for(i=0;i<3;i++)
		pthread_create(&wr[i],NULL,writer,&a[i]);
	for(i=3;i<6;i++)
		pthread_create(&wr[i],NULL,reader,&a[i]);
	for(i=0;i<6;i++)
		pthread_join(wr[i],NULL);
	
	return 0;
}
