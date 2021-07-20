#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define max 10
int stack[max];
pthread_mutex_t pop_mutex;
pthread_mutex_t push_mutex;
int top=-1; //to use the stack

void *push(void *arg)
{
	int number;
	pthread_mutex_lock(&push_mutex);
	pthread_mutex_lock(&pop_mutex);
	
	puts("Enter the value you wish to pusk on the stack:");
	scanf("%d",&number);
	
	top++;
	stack[top]=number;
	
	pthread_mutex_unlock(&pop_mutex);
	pthread_mutex_unlock(&push_mutex);
	
	printf("The value %i was pushed to the stack.\n",number);
	
	return NULL;
}

void *pop(void *arg)
{
	int k;
	
	pthread_mutex_lock(&pop_mutex);
	pthread_mutex_lock(&push_mutex);
	
	k=stack[top];
	top--;
	
	printf("The value popped is %i .\n",k);
	pthread_mutex_unlock(&push_mutex);
	pthread_mutex_unlock(&pop_mutex);
	
    return NULL;
}






int main(int argc, char ** argv)
{
	pthread_t tid1;
	pthread_t tid2;
	
	pthread_create(&tid1,NULL,push,NULL);
	pthread_create(&tid2,NULL,pop,NULL);
	puts("Both threads have been created up to this point.");
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	return 0;
}

