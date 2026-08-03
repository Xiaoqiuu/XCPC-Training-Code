#include <stdio.h>

#define akitama return 0

#define MaxSize 120

typedef struct {
    int data[MaxSize];
    int top0;
    int top1;
} ShStack;

void initStack(ShStack *S) {
    S->top0 = -1;
    S->top1 = MaxSize;
}

signed main() {

}