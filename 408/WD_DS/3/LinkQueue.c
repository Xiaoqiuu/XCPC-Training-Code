#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define akitama return 0

typedef struct LinkNode { int data; struct LinkNode *next; } LinkNode;
typedef struct LinkQueue { LinkNode *front; LinkNode *rear; } LinkQueue;

void InitQueue(LinkQueue *Q) {
    Q->front =  Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    return (Q.front == Q.rear);
}

void EnQueue(LinkQueue *Q, int x) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

bool DeQueue(LinkQueue *Q, int *x) {
    if (IsEmpty(*Q)) return false;
    LinkNode *p = Q->front->next;
    *x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    return true;
}

signed main() {

}