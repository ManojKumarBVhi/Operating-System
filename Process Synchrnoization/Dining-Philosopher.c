#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

sem_t mutex, S[N];
int state[N];
int phil[N] = {0,1,2,3,4};

void test(int phnum){
	if(state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[phnum] = EATING;
		sleep(2);
		printf("Philosopher %d is taking fork %d and %d\n",phnum+1, LEFT+1, phnum+1);
		printf("Philosopher %d is Eating\n",phnum+1);
		sem_post(&S[phnum]);
	}
}

void take_fork(int phnum){
	sem_wait(&mutex);
	state[phnum] = HUNGRY;
	printf("Philosopher %d is Hungry\n",phnum+1);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
	sleep(1);
}

void put_fork(int phnum){
	sem_wait(&mutex);
	state[phnum] = THINKING;
	printf("Philosopher %d is putting forks %d and %d down\n",phnum+1, LEFT+1, phnum+1);
	printf("Philosopher %d is Thinking\n",phnum+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *philosopher(void *num){
	while(1){
		int *i = num;
		sleep(1);
		take_fork(*i);
		sleep(0);
		put_fork(*i);
	}
}

int main(){
	sem_init(&mutex,0,1);
	int i;
	pthread_t p[N];
	for(i=0;i<N;i++)
		sem_init(&S[N],0,1);
	for(i=0;i<N;i++)
		pthread_create(&p[i],NULL,philosopher,&phil[i]);
	for(i=0;i<N;i++)
		pthread_join(p[i],NULL);
	
	return 0;
}
