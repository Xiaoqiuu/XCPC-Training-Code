#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define akitama return 0

// 循环双链表定义
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *CycleDLinkList;

// 循环双链表初始化
bool InitCycleDLinkList(CycleDLinkList *L) {
    *L = (DNode *)malloc(sizeof(DNode));
    if (*L == NULL) return false;
    (*L)->prior = (*L)->next = *L;
    return true;
}

// 循环双链表判空
bool isEmpty(CycleDLinkList L) {
    if (L->next == L) return true;
    return false;
}

// 循环双链表判断结点是否为尾结点
bool isTail(CycleDLinkList L, DNode *p) {
    if (p->next == L) return true;
    return false;
}

// 循环双链表插入
// 在p结点后插入s结点
bool InsertNextDNode(DNode *p, DNode *s) {
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}

// 删除p的后继结点q
bool DeleteNextDNode(DNode *p, DNode *q) {
    q->next->prior = p;
    p->next = q->next;
    free(q);
    return true;
}

signed main() {
    CycleDLinkList L;
    InitCycleDLinkList(&L);
}