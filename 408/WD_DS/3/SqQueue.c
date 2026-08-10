/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-08-02 07:20:48
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-08-08 17:11:04
 * @FilePath: /workspace/408/WD_DS/3/SqQueue.c
 * @Description: XCPC | 408 | Unity | Agents
 */
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

bool QueueFull(SqQueue Q) {
    return (Q->rear + 1) % MaxSize == Q->front; // 队列满的条件是 rear 指针指向 MaxSize 时，front 指针指向 0
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
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize; // 队列头指针向后移动一位
    return true;
}

bool GetHead(SqQueue Q, int *x) {
    if (QueueEmpty(Q)) return false;
    *x = Q->data[Q->front];
    return true;
}

signed main() {

}