/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-07-21 21:16:40
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-07-21 21:22:52
 * @FilePath: /workspace/408/WD_DS/2/2-CycleLinkList.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define akitama return 0

typedef struct LNode {
    int data;
    struct LNode *next; // 指向下一个节点的指针
} LNode, *CycleLinkList;

bool InitCycleLinkList(CycleLinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) return false;
    (*L)->next = *L; // 指向自身，形成环
    return true;
}

bool empty(CycleLinkList L) {
    if (L->next == L) return true;
    return false;
}

bool isTail(CycleLinkList L, LNode *p) {
    if (p->next == L) return true;
    return false;
}



signed main() {

    akitama;
}