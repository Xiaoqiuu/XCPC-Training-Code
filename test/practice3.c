#include <stdio.h>
#include <stdbool.h>

#define akitama return 0
#define M 100007
const int N = 100007;

int a[M];

signed main() {
    for (int i = 0; i < 10; ++ i) {
        a[i] = i;
        printf("%p ", a[i]);
    }
    akitama;
}