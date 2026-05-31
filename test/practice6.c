/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-28 02:02:08
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-25 19:49:15
 * @FilePath: /workspace/test/practice6.c
 * @Description: XCPC | 408 | Unity | Agents
 */
#include <stdio.h>
#include <stdlib.h>
#define akitama return 0

typedef struct Apple{
    char* name;
    int num;
}Apple;

signed main() {
    Apple* apple;
    apple = (Apple*)malloc(sizeof(Apple));
    apple->name = "Apple";
    apple->num = 10;
    printf("Apple name: %s, Apple num: %d\n", apple->name, apple->num);
    free(apple);
    akitama;
}