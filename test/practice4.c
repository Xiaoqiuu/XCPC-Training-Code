#include <stdio.h>
#include <stdlib.h>
#define akitama return 0
/*
    List
    Study time: 2026-04-18 09:00:00
*/

typedef struct LNode{
    int data;
    struct LNode *next;
}ListNode, *LinkList;

void InitList(ListNode **L){
    *L = (ListNode*)malloc(sizeof(ListNode));
}