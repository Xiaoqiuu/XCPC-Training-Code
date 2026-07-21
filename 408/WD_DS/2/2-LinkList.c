/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-07-15 21:33:36
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-07-21 16:52:40
 * @FilePath: /workspace/408/WD_DS/2/2-LinkList.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#define bool _Bool
#define akitama return 0

typedef struct LNode{
    int data;
    struct LNode *next;
}ListNode, *LinkList;

bool Empty(LinkList L) {
    return (L == NULL);
    // 如果带头节点
    return L->next == NULL;
}

// 带头节点插入版本
// 插入节点的值为e
bool LinkInsert(LinkList L, int i, int e) {
    if (i < 1) return false;
    ListNode *p = L; // 默认指向头节点 头节点是第0个节点（不存数据） 
    int j = 0;
    while (p != NULL && j < i - 1) { // 循环找到第i-1个节点
        p = p->next; // 指针p指向当前扫到的节点
        ++j; // 扫到了第j个节点
    }
    if (p == NULL) return false;
    ListNode *s  = (ListNode *)malloc(sizeof(ListNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool LinkInsert_WithoutHead(LinkList *L, int i, int e) {
    if (i < 1) return false;
    else if (i == 1) {
        ListNode *s = (ListNode *)malloc(sizeof(ListNode));
        s->data = e;
        s->next = *L;
        *L = s; // 头节点指向新插入的节点
        return true;
    }
    ListNode *p = *L; // 默认指向头节点
    int j = 1;
    while (p != NULL && j < i - 1) { // 循环找到第i-1个节点
        p = p->next; // 指针p指向当前扫到的节点
        ++j; // 扫到了第j个节点
    }
    if (p == NULL) return false;
    ListNode *s  = (ListNode *)malloc(sizeof(ListNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 尾插法
bool TailInsert(ListNode *p, int e) {
    if (p == NULL) return false;
    ListNode *s = (ListNode*)malloc(sizeof(ListNode));
    if (s == NULL) return false;
    s->data = e;
    s->next = p->next;
    p->next =s;
    return true;
}

// 按位查找
ListNode* GetElem(LinkList L, int i) {
    if (i < 0) return NULL;
    ListNode *p = L->next; // 默认指向头节点的下一个节点
    int j = 1;
    while (p != NULL && j < i) { // 循环找到第i个节点
        p = p->next; // 指针p指向当前扫到的节点
        ++j; // 扫到了第j个节点
    }
    return p;
}

bool ListDelete(LinkList *L, int i) {
    if (i < 1) return false;
    // 查找操作 如果封装了查找操作那就直接调用GetElem()即可
    ListNode *p = *L; // 默认指向头节点
    int j = 1;
    for (; p != NULL && j < i; ++j) {
        p = p->next;
    }
    if (p == NULL) return false;
    if (p->next == NULL) return false;
    ListNode *q = p->next; // q指向要删除的节点
    p->next = q->next; // p的next指向q的next
    free(q); // 释放q所指向的节点
    return true;
}

ListNode* LocateElem(LinkList L, int e) {
    ListNode *p = L->next; // 默认指向头节点的下一个节点
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p; // 如果没找到 p最后指向null 就返回null了
}

int ListLength(LinkList L) {
    int len = 0;
    ListNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        ++len;
    }
    return len;
}

LinkList MakeList_TailInsert(LinkList *L) {
    int x = 0;
    *L = (LinkList)malloc(sizeof(ListNode));
    ListNode *s = NULL, *r = *L;
    // 这里描述一下 王道的写法是
    // scanf("%d", &x); while (x!=9999)
    // 也是正常读入数据 只不过如果读到的数字是9999 那么就停止读取
    while (scanf("%d", &x) != EOF) {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = x;
        r->next = s;
        r = s;
        // r = r->next; // 这里是错误的，因为r是头节点，不能直接指向r->next
    }
    r->next = NULL; // 尾节点的next指向NULL
    return *L;
}

LinkList MakeList_HeadInsert(LinkList *L) {
    ListNode *s = NULL;
    int x = 0;
    *L = (LinkList)malloc(sizeof(ListNode));
    (*L)->next = NULL;
    while (scanf("%d", &x) != EOF) {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
    }
    return *L;
}

LinkList LinkList_Revert(LinkList *L) {
    ListNode *pre = NULL, *p = (*L)->next, *next = NULL;
    while (p != NULL) {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    (*L)->next = pre;
    return *L;
}

signed main() {
    
    akitama;
} 