// 随机数发生器

#include <iostream>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define akitama return 0

#define A 48271L
#define M 2147483647L
#define Q ( M / A )
#define R ( M % A )

static ull seed = 1;

double
Random() {
    ll tmpseed;
    tmpseed = A * ( seed % Q ) - R * ( seed / Q );
    if ( tmpseed >= 0 ) {
        seed = tmpseed;
    } else {
        seed = tmpseed + M;
    }
    return ( double ) seed / M;
}

void
Initialize(ull initval) {
    seed = initval;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    /*
    Initialize(1114567890987654L);
    for (int i = 0; i < 10; i++) {
        cout << Random() << " ";
    }
    */

    printf("The answer is : %d", 'd' - 'a');

    akitama;
}