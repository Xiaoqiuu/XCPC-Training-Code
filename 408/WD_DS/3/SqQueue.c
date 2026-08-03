#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 100
typedef struct SqQueue {
    int data[MaxSize];
    int front, rear; // 队头指针和队尾指针
} *SqQueue;

// 初始化队列 这里按照队头队尾指针分别指向 0 0
void InitQueue(SqQueue Q) {
    Q->front = 0, Q->rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q->front == Q->rear;
}

bool EnQueue(SqQueue Q, int x) {
    if (Q->rear == MaxSize) {
        return false;
    }
    Q->data[Q->rear++] = x;
    return true;
}

bool DeQueue(SqQueue Q, int *x) {
    if (QueueEmpty(Q)) return false;
    *x = Q->data[Q->front++];
    return true;
}

int GetHead(SqQueue Q) {
    if (QueueEmpty(Q)) return -1;
    return Q->data[Q->front];
}

signed main() {

}