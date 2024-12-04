#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
typedef struct DEQueue {
	Node* head;
	Node* tail;
}DEQueue;
DEQueue* createQueue();
bool isEmpty(DEQueue* pQueue);
void addFront(DEQueue* pQueue, int data);
void addTail(DEQueue* pQueue, int data);
void traverseQueue(DEQueue* q);
int remove(DEQueue* pQueue);
DEQueue* createQueue() {
	DEQueue* pQueue = (DEQueue*)malloc(sizeof(DEQueue));
	if (pQueue == NULL) {
		exit(-1);
	}
	pQueue->head = NULL;
	pQueue->tail = NULL;
	return pQueue;
}
bool isEmpty(DEQueue* pQueue) {
	return pQueue->head == NULL;
}

void addFront(DEQueue* pQueue, int data) {
	if (pQueue->head == NULL)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		if (pNewNode == NULL) {
			exit(-1);
		}
		pNewNode->data = data;
		pQueue->head = pNewNode;
		pQueue->tail = pNewNode;
		return;
	}
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		exit(-1);
	}
	pNewNode->data = data;
	pNewNode->next = pQueue->head;
	pQueue->head->prev = pNewNode;
	pQueue->head = pNewNode;

}
void addTail(DEQueue* pQueue, int data) {
	if (pQueue->head == NULL)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		if (pNewNode == NULL) {
			exit(-1);
		}
		pNewNode->data = data;
		pQueue->head = pNewNode;
		pQueue->tail = pNewNode;
		return;
	}
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		exit(-1);
	}
	pNewNode->data = data;
	pQueue->tail->next = pNewNode;
	pNewNode->prev = pQueue->tail;
	pNewNode->next = NULL;
	pQueue->tail = pNewNode;
}
	int remove(DEQueue* pQueue)
	{
		Node* temp = pQueue->head;
		int val = temp->data;
		pQueue->head = temp->next;
		free(temp);
		return val;
	}
void traverseQueue(DEQueue* q)
{
	if (!isEmpty(q))
	{
		Node* curr = q->head;
		while (curr != NULL) {
			printf("%d\n", curr->data);
			curr = curr->next;
		}
	}
	return;
}
int main()
{
	DEQueue* pQueue = createQueue();
	addTail(pQueue, 1);
	addTail(pQueue, 2);
	addTail(pQueue, 3);
	addTail(pQueue, 4);
	addTail(pQueue, 5);
	remove(pQueue);
	remove(pQueue);
	remove(pQueue);
	traverseQueue(pQueue);
	printf("Tail is: %d\n", pQueue->tail->data);
}