#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#define akitama return 0

using ll = long long;
using ld = long double;

int main() {
    ll n;cin >> n;
    ld num = 0;
    num = (ld)pow(1/3.0, n);
    printf("%.30Lf\n", num);
    printf("Time used: %.3fs",  (double)clock() / CLOCKS_PER_SEC);
    akitama;
}