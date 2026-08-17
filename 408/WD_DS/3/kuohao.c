#include <stdbool.h>
#define MaxSize 1000 + 7
#include <string.h>
typedef struct {
    char data[MaxSize];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

bool Push(Stack *S, char x) {
    if (S->top == MaxSize - 1) {
        return false;
    }
    S->data[++ S->top] = x;
    return true;
}

bool Pop(Stack *S, char *x) {
    if (S->top == -1) {
        return false;
    }
    *x = S->data[S->top--];
    return true;
}

bool IsEmpty(Stack *S) {
    return S->top == -1;
}

bool isValid(char* s) {
    Stack st;
    InitStack(&st);
    int len = strlen(s);
    for (int i = 0; i < len; ++ i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            Push(&st, s[i]);
        } else {
            if(IsEmpty(&st)) return false;
            char top = st.data[st.top];
            if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{')) {
                Pop(&st, &top);
            } else {
                return false;
            }
        }
    }
    return IsEmpty(&st);
}



