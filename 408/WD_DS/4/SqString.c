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

#define akitama return 0

signed main() {
    HString str;
    str.ch = (char *)malloc(MaxLength * sizeof(char));
    str.length = 0;
    free(str.ch);
    akitama;

}