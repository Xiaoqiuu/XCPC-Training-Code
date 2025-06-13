#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define akitama return 0

#define N 1024
static char *buffer[N];



signed main(int argc, char *argv[]) {
    //extern char* hello;
    char hello[] = "hello";
    printf("%s\n", &hello[0]);
/*
    int i, a[10];
    for (int i = 1; i <= 10; ++ i) {
        a[i] = 0;
    }
*/
    int x = 10;
    if ((3 > 2) || ((x += 29) == 39)) {
        printf("Yes\nx = %d\n", x);
    } else {
        printf("No\nx = %d\n", x);
    }

    akitama;
}