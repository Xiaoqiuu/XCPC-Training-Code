/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-25 20:09:31
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-26 15:03:41
 * @FilePath: /workspace/test/practice7.c
 * @Description: XCPC | 408 | Unity | AgentsF
 */
#include <stdio.h>
#include <stdlib.h>

#define akitama return 0

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    int ltag;
    int rtag;
} ThreadNode, *ThreadTree;

// 按先序序列创建二叉树，# 表示空结点
ThreadTree Create() {
    char c;
    scanf(" %c", &c);

    if (c == '#') return NULL;

    ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));

    T->data = c;
    T->ltag = 0;
    T->rtag = 0;

    T->left = Create();
    T->right = Create();

    return T;
}

// 中序线索化
void InThread(ThreadTree p, ThreadTree* pre) {
    if (p == NULL) return;

    InThread(p->left, pre);

    if (p->left == NULL) {
        p->left = *pre;
        p->ltag = 1;
    } else {
        p->ltag = 0;
    }

    if (*pre != NULL && (*pre)->right == NULL) {
        (*pre)->right = p;
        (*pre)->rtag = 1;
    }

    *pre = p;

    InThread(p->right, pre);
}

// 创建中序线索二叉树
void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;

    if (T != NULL) {
        InThread(T, &pre);

        pre->right = NULL;
        pre->rtag = 1;
    }
}

// 中序遍历线索二叉树
void InOrder(ThreadTree T) {
    ThreadTree p = T;

    while (p != NULL) {
        while (p->ltag == 0) {FF
            p = p->left;
        }

        printf("%c ", p->data);

        while (p->rtag == 1 && p->right != NULL) {
            p = p->right;
            printf("%c ", p->data);
        }

        p = p->right;
    }
}

signed main() {
    ThreadTree T;
    T = Create();
    CreateInThread(T);
    InOrder(T);
    akitama;
}