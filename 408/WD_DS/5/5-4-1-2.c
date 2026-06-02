#include <stdio.h>

#define x 0
#define akitama return (x);
#define MAX_SIZE 100
typedef struct CTNode{
    int child;
    struct CTNode *next;
}CTNode;

typedef struct CTBox{
    char data;
    struct CTNode *firstchild;
}CTBox;

typedef struct CTree{
    CTNode CTNode[MAX_SIZE];
    int n, r;
}CTree;


signed main() {

    akitama
}