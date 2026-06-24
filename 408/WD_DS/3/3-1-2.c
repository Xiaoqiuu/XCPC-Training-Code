/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-06-24 20:17:21
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-06-24 21:14:10
 * @FilePath: /workspace/408/WD_DS/3/3-1-2.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdbool.h>

#define akitama return 0

#define MaxSize 10 // 定义栈元素的最大数量
typedef struct SqStack {
    int data[MaxSize];
    int top; // 栈顶指针
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1; // 初始化栈顶指针为-1
};

bool StackEmpty(SqStack *S) {
    return S->top == -1; // 判断栈是否为空
};

bool Push(SqStack *S, int x) {
    if (S->top == MaxSize - 1) {
        printf("栈满，无法入栈\n");
        return false;
    }
    /*
        这里可以这样写
        S->top = S->top + 1;
        S->data[S->top] = x;
    */
    S->data[++S->top] = x; // 入栈操作
    
    return true;
};

bool Pop(SqStack *S, int *x) {
    if (StackEmpty(S)) {
        printf("栈空，无法出栈\n");
        return false;
    }

    *x = S->data[S->top--]; // 出栈操作
    return true;
};

bool GetTop(SqStack *S, int *x) {
    if (StackEmpty(S)) {
        printf("栈空，无法获取栈顶元素\n");
        return false;
    }

    *x = S->data[S->top]; // 获取栈顶元素
    return true;
};




signed main() {
    SqStack S;
    InitStack(&S);
    akitama;
}