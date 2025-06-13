#include <iostream>
#include <cstring>
#include <algorithm>
#define akitama return 0;
using namespace std;
using ll = long long;
int main() {
    char a[4];
    scanf("%s", &a);
    printf("%s%s%s\n", a[2],a[1],a[0]);
    akitama;
}

//char 往大了开 注意最后输入'\0'