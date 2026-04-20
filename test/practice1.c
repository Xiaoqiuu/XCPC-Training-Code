#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define akitama return 0
const int N = 12;
typedef struct Student{
    int age;
    bool isMale;
    char name[12];
    struct Student *whoisMonitor;
}Stu;

#define MaxSize 10 // 定义最大长度
typedef struct{
    int data[MaxSize]; // 用静态“数组”存放数据元素
    int length; // 顺序表当前长度
}SqList; // 顺序表的类型定义（静态分配方式）

void InitList(SqList* L) {
    for (int i = 0; i < MaxSize; ++ i) {
        L->data[i] = 0;
    } L->length = 0;
}

#define InitSize 100
typedef struct DynamicSqList{
    int *data;
    int Maxsize, length;
}DySqList;

void InitList2(DySqList *L) {
    L->data = (int*)malloc(sizeof(DySqList) * InitSize);
    L->length = 0;
    L->Maxsize = InitSize;
}

bool ListDelete(SqList *L, int i, int *e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; ++ j) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

int LocateElem(SqList L, int e) {
    int i = 0;
    for (; i < L.length; ++ i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) return 0;
    return L.data[i - 1];
}
 
signed main() {
    int num = sizeof(Stu);
    printf("Size of Student is %d.\n", num);
    struct Student *ghq;
    Stu *qy;

    qy = malloc(sizeof(Stu));

    // qy->age = 22;
    // ghq->age = 11;
    free(qy);

    SqList *s;
    s = malloc(sizeof(SqList));
    InitList(s);
    // s = malloc(sizeof(SqList));
    // s->data[1] = 10;
    printf("The length of the list is %d.\n", s->length);
    free(s);
}