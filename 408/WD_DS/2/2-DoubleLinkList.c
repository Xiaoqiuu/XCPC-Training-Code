/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-07-21 17:00:53
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-07-21 21:02:09
 * @FilePath: /workspace/408/WD_DS/2/2-DoubleLinkList.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define akitama return 0

typedef struct DNode{
    int data;
    struct DNode *next, *prior;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList *L) {
    *L = (DNode *)malloc(sizeof(DNode));
    DNode *s = *L;
    if (*L == NULL) return false;
    s->prior = s->next = NULL; // prior 永远指向NULL 因为是头节点
    return true;
}

// 双链表的插入 在p之后插入s
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL) p->next->prior = s; // 如果p结点有后继节点
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p结点后面的结点
bool DeleteNextDNode(DNode *p) {
    if (p == NULL) return false;
    DNode *q = p->next;
    if (q == NULL) return false;
    p->next = q->next;
    if (q->next != NULL) q->next->prior = p;
    free(q);
    return true;
}

void DestoryList(DLinkList *L) {
    DNode *p = *L;
    while (p->next != NULL) {
        DeleteNextDNode(*L);
    }
    free(L);
    *L = NULL; // 释放指针
}

signed main() {
    DLinkList L;
    if(InitDLinkList(&L)){
        printf("List Created.\n");
    };
    akitama;
}