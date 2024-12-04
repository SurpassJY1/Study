#include <stdlib.h>  
#include <stdbool.h>  
#include <stdio.h>

#define INITIAL_CAPACITY 3  

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

// ��ʼ��˫�˶���  
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    deque->front = 0;
    deque->rear = -1;
    deque->size = 0;
    deque->capacity = INITIAL_CAPACITY;
    return deque;
}

// �������Ƿ�Ϊ��  
bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

// �������Ƿ�����  
bool isFull(Deque* deque) {
    return deque->size == deque->capacity;
}

// �ڶ���ǰ�˲���Ԫ��  
void insertFront(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity; // ѭ������  
    deque->data[deque->front] = value;
    deque->size++;
}

// �ڶ��к�˲���Ԫ��  
void insertRear(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }
    deque->rear = (deque->rear + 1) % deque->capacity; // ѭ������  
    deque->data[deque->rear] = value;
    deque->size++;
}

// �Ӷ���ǰ��ɾ��Ԫ��  
int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        exit(EXIT_FAILURE); // ���߷���һ������ֵ��ʾ����  
    }
    int value = deque->data[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return value;
}

// �Ӷ��к��ɾ��Ԫ��  
int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        exit(EXIT_FAILURE); // ���߷���һ������ֵ��ʾ����  
    }
    int value = deque->data[deque->rear];
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity; // ѭ������  
    deque->size--;
    return value;
}

// ��ȡ����ǰ��Ԫ�أ���ɾ����  
int peekFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // ���߷���һ������ֵ��ʾ����  
    }
    return deque->data[deque->front];
}

// ��ȡ���к��Ԫ�أ���ɾ����  
int peekRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // ���߷���һ������ֵ��ʾ����  
    }
    return deque->data[deque->rear];
}

// ��ӡ�����е�����Ԫ��  
void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = deque->front;
    for (int count = 0; count < deque->size; count++) {
        printf("%d ", deque->data[i]);
        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

// �ͷŶ��е��ڴ�  
void freeDeque(Deque* deque) {
    free(deque->data);
    free(deque);
}

int main() {
    Deque* deque = createDeque();

    insertRear(deque, 1);
    insertRear(deque, 2);
    insertFront(deque, 3);
    printDeque(deque);

   
    return 0;
}