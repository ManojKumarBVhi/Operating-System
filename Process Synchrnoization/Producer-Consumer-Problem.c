#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int count = 0;
sem_t empty,full,mutex;

void *producer(void *args){
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("Producer produced %d process \n",++count);
	sem_post(&mutex);
	sem_post(&full);
}

void *consumer(void *args){
	sem_wait(&full);
	sem_wait(&mutex);
	printf("Consumer consumed %d process \n", count--);
	sem_post(&mutex);
	sem_post(&empty);
}

int main(){
	sem_init(&mutex,0,1);
	sem_init(&empty,0,5);
	sem_init(&full,0,0);
	
	int m,n,i,j;
	printf("Enter the producer values : ");
	scanf("%d",&m);
	
	printf("Enter the consumer values : ");
	scanf("%d",&n);
	
	pthread_t p[m];
	for(i=0;i<m;i++)
		pthread_create(&p[i],NULL,producer,NULL);
	for(i=0;i<m;i++)
	pthread_join(p[i],NULL);
	
	pthread_t c[n];
	for(j=0;j<n;j++)
		pthread_create(&c[j],NULL,consumer,NULL);
	for(j=0;j<n;j++)
		pthread_join(c[j],NULL);
	
	return 0;
}
