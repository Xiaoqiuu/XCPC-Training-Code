/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-25 20:09:31
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-25 21:12:19
 * @FilePath: /workspace/test/practice7.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdlib.h>
#define akitama return 0

/*
    自制线索二叉树
*/

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    int ltag;
    int rtag;
} ThreadNode, *ThreadTree;

ThreadTree Create() {
    char c;
    scanf("%c", &c);
    if (c == '#') return NULL;
    ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
    T->data = c;
    T->left = Create();
    T->right = Create();
    return T;
}
signed main() {
    ThreadTree T;
    // T0 = (*ThreadNode)malloc(sizeof(ThreadNode));
    // T0->data = 'A';
    // T0->left = T0->right = NULL;
    // T0->ltag = T0->rtag = 0;
    T = Create();
    akitama;
}