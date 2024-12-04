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

// 初始化双端队列  
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    deque->front = 0;
    deque->rear = -1;
    deque->size = 0;
    deque->capacity = INITIAL_CAPACITY;
    return deque;
}

// 检查队列是否为空  
bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

// 检查队列是否已满  
bool isFull(Deque* deque) {
    return deque->size == deque->capacity;
}

// 在队列前端插入元素  
void insertFront(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity; // 循环数组  
    deque->data[deque->front] = value;
    deque->size++;
}

// 在队列后端插入元素  
void insertRear(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }
    deque->rear = (deque->rear + 1) % deque->capacity; // 循环数组  
    deque->data[deque->rear] = value;
    deque->size++;
}

// 从队列前端删除元素  
int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        exit(EXIT_FAILURE); // 或者返回一个特殊值表示错误  
    }
    int value = deque->data[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return value;
}

// 从队列后端删除元素  
int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        exit(EXIT_FAILURE); // 或者返回一个特殊值表示错误  
    }
    int value = deque->data[deque->rear];
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity; // 循环数组  
    deque->size--;
    return value;
}

// 获取队列前端元素（不删除）  
int peekFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // 或者返回一个特殊值表示错误  
    }
    return deque->data[deque->front];
}

// 获取队列后端元素（不删除）  
int peekRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE); // 或者返回一个特殊值表示错误  
    }
    return deque->data[deque->rear];
}

// 打印队列中的所有元素  
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

// 释放队列的内存  
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