#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LiStack;

bool initStack(LiStack *L) {
    (*L)->next = NULL;
    return true;
}

bool Push(LiStack *L, int x) {
    LiStack p = (LiStack)malloc(sizeof(LinkNode));
    if (p == NULL) return false;
    p->data = x;
    p->next = *L;
    *L = p;
    return true;
}

bool Pop(LiStack *L, int *x) {
    if (*L == NULL) return false;
    LiStack p = *L;
    *x = p->data;
    *L = p->next;
    free(p);
    return true;
}

int GetTop(LiStack L) {
    return (L != NULL)? L->data : -1;
}

bool isEmpty(LiStack L) {
    return L == NULL;
}



signed main() {

}