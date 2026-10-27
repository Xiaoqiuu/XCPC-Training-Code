/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-08-03 09:31:37
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-08-21 00:47:34
 * @FilePath: /workspace/408/WD_DS/4/SqString.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定长字符串
#define MaxLength 255
typedef struct {
    char ch[MaxLength];
    int length;
} SString;

// 可变长字符串 动态数组实现（堆分配存储）
typedef struct {
    char *ch; // 按串长分配存储区，ch指向存储区的首地址
    int length; // 字符串长度
} HString;

typedef struct StringNode {
    char ch[4];
    struct StringNode *next;
} StringNode, * String;


#define akitama return 0

bool SubString(SString *sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; ++ i) {
        sub->ch[i - pos] = S.ch[i];
    }
    sub->length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; ++ i) {
        if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
    } return S.length - T.length;
}

int StrLength(SString S) {
    return S.length;
}

int Index(SString S, SString T) {
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1) {
        SubString(&sub, S, i, m);
        if (StrCompare(sub, T) == 0) return i;
        ++ i; 
    }
    return 0;
}

signed main() {
    HString str;
    str.ch = (char *)malloc(MaxLength * sizeof(char));
    str.length = 0;
    free(str.ch);
    akitama;

}