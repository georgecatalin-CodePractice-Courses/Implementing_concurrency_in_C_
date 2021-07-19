#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runThread1(void *arg);
void *runThread2(void *arg);

int main(int argc, char **argv)
{
	pthread_t tid1;
	pthread_t tid2;
	
	puts("This is running in the main() thread.");
	
	pthread_create(&tid1,NULL,runThread1,NULL);
	pthread_create(&tid2,NULL,runThread2,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	puts("The newly spawned threads are both over now.");

	return 0;
}

void *runThread1(void *arg)
{
	int i;
	puts("This is running from thread number 1.");
	
	for(i=0;i<=20;i++)
	{
		printf("Thread 1 - %d\n",i);
	}
	
	return NULL;
}

void *runThread2(void *arg)
{
	int i;
	puts("This is running from thread number 2.");
	
	for(i=0;i<=20;i++)
	{
		printf("Thread 2 - %d\n",i);
	}

	return NULL;
	
}
