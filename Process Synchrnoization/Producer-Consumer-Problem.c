#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int counter = 0;
sem_t empty, full, mutex;

void * producer(void * args){
  sem_wait(&empty);
  sem_wait(&mutex);
  printf("Producer process produced, process %d\n", ++counter);
  sem_post(&mutex);
  sem_post(&full);
}

void * consumer(void * args){
  sem_wait(&full);
  sem_wait(&mutex);
  printf("Consumer process consumed, process %d\n", counter--);
  sem_post(&mutex);
  sem_post(&empty);
}

int main(){
  sem_init(&empty, 1 , 5);
  sem_init(&full, 1, 0);
  sem_init(&mutex, 1, 1);
  int m,n;
  printf("Enter the value of producer threads : ");
  scanf("%d",&m);
  printf("Enter the value of Consumer threads : ");
  scanf("%d", &n);
  pthread_t ptid[m];
  for(int i=0; i<m; i++)
      pthread_create(&ptid[i],NULL, producer, NULL);
  for(int i=0; i<m; i++)
      pthread_join(ptid[i],NULL);
  
  pthread_t tid[n];
  for(int j=0; j<n; j++)
      pthread_create(&tid[j], NULL, consumer, NULL);
  for(int j=0; j<n; j++)
      pthread_join(tid[j], NULL);

  return 0;
}
