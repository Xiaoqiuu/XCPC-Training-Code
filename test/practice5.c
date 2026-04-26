/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-24 19:11:20
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-25 21:32:41
 * @FilePath: /workspace/test/practice5.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define akitama return 0

/*
    二叉树的顺序存储，采用数组表示法，数组的下标表示结点的位置，数组的元素表示结点的值。
    数组的第一个元素表示根结点，数组的第二个元素表示左子树的根结点，数组的第三个元素表示右子树的根结点。
    若某结点的左子树的根结点下标为2i-1，右子树的根结点下标为2i，则其父结点的下标为(i+1)/2-1。
*/
#define MaxSize 100
typedef struct TreeNode {
    int val; // 结点值
    bool isEmpty; // 是否为空结点 空？1:0
}TreeNode;

TreeNode T[MaxSize]; // 二叉树数组

void InitTree(int i) {
    for (int j = 1; j <= i; ++ j)
    T[i].isEmpty = true;
}

void start_TreeNode() {
    printf("请输入一共有多少个结点\n");
    int n;
    scanf("%d", &n);
    InitTree(n);
    printf("请输入结点值\n");
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &T[i].val); 
        T[i].isEmpty = false;
    }
    printf("查找结点的父亲，请输入结点编号：\n");
    int tar = -1;
    scanf("%d", &tar);
    int h = ceil(log2(tar+1));
    printf("父亲结点是%d，其值是%d\n", (tar+1)/2-1, T[(tar+1)/2-1].val);
    printf("当前结点高度：%d\n", h);
}

/*
    二叉树的链式存储，采用链表表示法，链表的每个结点包含两个域，一个是结点值，另一个是指向其左子树的指针。
    若某结点的左子树的指针指向其左子树的第一个结点，则其右子树的指针指向其右子树的第一个结点。
*/
typedef struct BiTNode{
    int data; // 结点值
    struct BiTNode *lchild, *rchild; // 左右孩子指针
    // struct BiTNode *parent; // 父结点指针 组成三叉链表
} BiTNode, *BiTree;

// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%d\n", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%d\n", T->data);
        InOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%d\n", T->data);
    }
}

void start_BiTNode() {
    // 演示用 防止与之前代码冲突 请在main函数调用/直接改名为main函数
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    printf("二叉树的链式存储\n");
    printf("根结点的值：%d\n", root->data);
    BiTree p = root->lchild;
    p = (BiTree)malloc(sizeof(BiTNode));
    p->data = 2;
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;
}

signed main() {
    // start_TreeNode();
    start_BiTNode();
    akitama;
}