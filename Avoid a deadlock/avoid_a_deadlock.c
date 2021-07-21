#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10
int stack[MAX];

pthread_mutex_t push_mutex;
pthread_mutex_t pop_mutex;
int top=-1;

void *push(void *arg);
void *pop(void *arg);

int main(int argc, char **argv)
{
	pthread_t tid1;
	pthread_t tid2;

	
	pthread_create(&tid1,NULL,&push,NULL);
	pthread_create(&tid2,NULL,&pop,NULL);
	puts("Both threads have been created.");
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	return 0;
}

void *push(void *arg)
{
	int number;
	pthread_mutex_lock(&push_mutex);
	sleep(2);
	pthread_mutex_lock(&pop_mutex);
	
	puts("Enter the value to push on the stack:");
	scanf("%d",&number);
	
	top++;
	stack[top]=number;
	
	pthread_mutex_unlock(&pop_mutex);
	pthread_mutex_unlock(&push_mutex);
	printf("The value %i was pushed on the stack.\n", number);
	
	return NULL;
}

void *pop(void *arg)
{
	int k;
	pthread_mutex_lock(&push_mutex);
	sleep(2);
	pthread_mutex_lock(&pop_mutex);
	
	k=stack[top];
	top--;
	
	pthread_mutex_unlock(&pop_mutex);
	pthread_mutex_unlock(&push_mutex);
	
	printf("The value popped from the stack is %i .\n",k);
	
	return NULL;
}

