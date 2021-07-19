#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_mutex_t lock;

void *runThread(void *arg);

int main(int argc, char **argv)
{
	puts("This is running in the main thread");
	
	if(pthread_mutex_init(&lock,NULL)!=0)
	{
		puts("The mutex init has failed.");
	}
	
	pthread_create(&tid1,NULL,runThread,NULL);
	pthread_create(&tid2,NULL,runThread,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	pthread_mutex_destroy(&lock);
	
	return 0;
}

void *runThread(void *argc)
{
	pthread_mutex_lock(&lock);
	
	pthread_t tid=pthread_self();
	
	if(pthread_equal(tid,tid1))
	{
		puts("First thread is running now.");
	}
	else
	{
		puts("Second thread is running now.");
	}
	
	puts("Processing the shared resource now");
	sleep(10);
	
	if (pthread_equal(tid,tid1))
	{
		puts("First thread completed now");
	}
	else
	{
		puts("Second thread completed now");
	}
	
	pthread_mutex_unlock(&lock);
	return NULL;
}
