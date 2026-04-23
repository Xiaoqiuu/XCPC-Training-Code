/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-17 09:08:57
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-20 23:59:07
 * @FilePath: /workspace/test/practice4.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define akitama return 0
/*
    Study time: 2026-04-18 09:00:00
*/

typedef struct LNode{
    int data;
    struct LNode *next;
}ListNode, *LinkList;

bool InitList(LinkList *L){
    *L = NULL;
    return true;
}

bool InitList2(LinkList *L) {
    *L = (LinkList)malloc(sizeof(ListNode));
    if (*L == NULL) {
        return false;
    }
    (*L)->next = NULL;
    return true;
}