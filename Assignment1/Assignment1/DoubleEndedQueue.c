#include<stdio.h>
#include "DEQueue.h"

//initialize structure of DEQueue
typedef struct DEQueue
{
	int size;
	int front;
	int rear;
	int deque[CAPACITY];
}DEQueue;

//create a DEQueue and return a pointer to it
DEQueue* createDEQue()
{
	//allocate a memory of DEQueue
	DEQueue* deque = (DEQueue*)malloc(sizeof(DEQueue));
	//if memory allocation failed, notice the user
	if (deque == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(ERROR_NUM);
	}
	//initialize the data inside empty DEQueue
	deque->front = deque->rear = -1;
	deque->size = 0;
	return deque;
}
//check if the DEQueue is empty
bool isEmpty(DEQueue* deque)
{
	//if the DEQueue is empty, the size of it equals to zero
	return deque->size == 0;
}

//check if the DEQueue is full
bool isFull(DEQueue* deque)
{
	//if the DEQueue is full, the size of it equals to the capacity
	return deque->size == CAPACITY;
}

//insert data from rear of DEQueue
void rearInsert(DEQueue* deque, int num)
{
	//if the DEQueue is full, we need to notice the user and exit
	if (isFull(deque))
	{
		fprintf(stderr, "The DEQueue is already full");
		exit(ERROR_NUM);
	}
	if (isEmpty(deque))
	{
		//if the DEQueue is empty, we need to refresh both front and rear
		deque->front = 0;deque->rear = 0;
	}
	deque->deque[deque->rear] = num;
	//use this to ensure the array is ringbuffer
	deque->rear = (deque->rear + 1) % CAPACITY;
	deque->size++;
}

//insert data from front of DEQueue
void frontInsert(DEQueue* deque, int num)
{
	//if the DEQueue is full, we need to notice the user and exit
	if (isFull(deque))
	{
		fprintf(stderr, "The DEQueue is full");
		exit(ERROR_NUM);
	}
	//if the DEQueue is empty, we need to fresh both front and rear at first
	if (isEmpty(deque))
	{
		deque->front = deque->rear = 0;
	}
	deque->deque[deque->front] = num;
	//refresh the front to ensure the array is ringbuffer
	deque->front = (deque->front - 1 + CAPACITY) % CAPACITY;
	deque->size++;
}

//delete data from rear of DEQueue and return the removed num
int delete(DEQueue* deque)
{
	//if the DEQueue is empty, we need to notice the user and exit the program
	if (isEmpty(deque))
	{
		fprintf(stderr, "The queue is empty already");
		exit(ERROR_NUM);
	}
	int deleted = deque->deque[(deque->rear-1+CAPACITY)%CAPACITY];
	deque->deque[deque->rear-1+CAPACITY ] = -1;
	deque->rear = (deque->rear - 1 + CAPACITY) % CAPACITY;
	deque->size--;
	//if the size equals to 0, it means the DEQueue backs to its initial condition
	if (deque->size==0)
	{
		//set the DEQueue backs to the initial condition
		deque->rear = deque->front = -1;
	}
	return deleted;
}

//this method is used to check each num inside the DEQueue
void traverse(DEQueue* deque)
{
	//check if the queue empty
	if (isEmpty(deque))
	{
		fprintf(stderr, "The queue is Empty");
		exit(-1);
	}
	//use p to record the front
	int p = deque->front;
	//print for size times
	for (int i = 0; i < deque->size; i++)
	{
		printf("%d: %d\n", p, deque->deque[p]);
		//moves p to the next
		p = (p + 1) % CAPACITY;
	}
}

//This method is used to get the max value inside the DEQueue
int getMax(DEQueue* deque)
{
	//check if the queue empty
	if (isEmpty(deque))
	{
		fprintf(stderr, "The queue is Empty");
		exit(-1);
	}
	//use p to record the front
	int p = deque->front;
	//use max to record the temporary max number
	int max = deque->deque[p];
	//print for size times
	for (int i = 0; i < deque->size; i++)
	{
		//moves p to the next
		p = (p + 1) % CAPACITY;
		if (max <= deque->deque[p])
		{
			max = deque->deque[p];
		}
	}
	//return the max number
	return max;
}

int main()
{
	DEQueue* deque = createDEQue();
	for (int i = 0; i < CAPACITY; i++)
	{
		frontInsert(deque, i + 1);
	}
	int deleted = delete(deque);
	printf("deleted: %d\n",deleted);
	for (int i = 0; i < CAPACITY-1; i++)
	{
		delete(deque);
	}
	int max = getMax(deque);
	printf("The max value in the Double-Ended Queue is %d\n",max);
	printf("The elements of queue are\n");
	traverse(deque);
	free(deque);
	return 0;
}