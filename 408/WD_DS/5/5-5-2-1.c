#include <stdio.h>

#define akitama return 0;

#define MAX_SIZE 100

typedef struct PTNode{
    int data;
    int parent;
}PTNode;

typedef struct PTree{
    PTNode nodes[MAX_SIZE];
    int n;
}PTree;

int Find(int S[], int x) {
    while (s[x] >= 0) {
        x = S[x];
        return x;
    }
}

void
Union(int S[], int root1, int root2) {
    if (root1 == root2) return;
    if (S[root2] > S[root1]) {
        S[root1] += S[root2];
        S[root2] = root1;
    } else {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}


signed
main() {
    akitama
}