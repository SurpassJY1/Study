#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef struct Stack {
	Node* top;
}Stack;
Stack* createStack();
void push(Stack* Stack, int data);
bool isEmpty(Stack* Stack);
void clearStack(Stack* Stack);
int peek(Stack* Stack);
bool isEmpty(Stack* Stack) {
	if (Stack->top == NULL)
	{
		return true;
	}
	return false;
}
Stack* createStack() {
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
	{
		return NULL;
	}
	pStack->top = NULL;
	return pStack;
}
void push(Stack* Stack, int data) {
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
	{
		printf("ERROR");
		exit(-1);
	}
	pNewNode->data = data;
	pNewNode->next = Stack->top;
	Stack->top = pNewNode;
}
int pop(Stack* Stack) {
	if (isEmpty(Stack))
	{
		free(Stack);
	}
	Node* removed = Stack->top;
	int data = removed->data;
	Stack->top = removed->next;
	removed->next = NULL;
	removed->data = 0;
	free(removed);
	return data;
}
void clearStack(Stack* Stack) {
	while (!isEmpty(Stack)) {
		pop(Stack);
	}
}
int peek(Stack* Stack) {
	if (isEmpty(Stack)) {
		return NULL;
	}
	int data = Stack->top->data;
	return data;
}
int main() {
	Stack* TestStack = createStack();
	if (TestStack == NULL)
	{
		printf("Error: Stack is NULL");
		exit(0);
	}
	push(TestStack, 1);
	push(TestStack, 2);
	push(TestStack, 3);
	push(TestStack, 4);
	printf("%d\n", peek(TestStack));
	printf("%d\n", TestStack->top->data);
	clearStack(TestStack);
	return 0;
}
