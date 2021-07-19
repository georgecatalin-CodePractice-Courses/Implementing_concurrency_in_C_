#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runThread(void *arg);

int main(int argc, char **argv)
{
	pthread_t tid;
	puts("This happens in the main function.");
	
	pthread_create(&tid,NULL,runThread,NULL);
	pthread_join(tid,NULL);
	puts("Main thread is over now");
	return 0;
}

void *runThread(void *arg)
{
	int i;
	puts("This happens in the newly spawned thread.");
	
	for(i=0;i<=5;i++)
	{
		printf("%3d\n",i);
	}
	
	return NULL;
}
