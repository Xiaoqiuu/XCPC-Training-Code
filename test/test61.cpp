#include <iostream>
#include <cstdlib>
#include <string>
// #include <algorithm>
using namespace std;

#define akitama return 0
#define ll long long int
typedef ll i64;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

i64 _power(i64 a,  i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

void solve() {
    string s = "1122";
    i64 num = atoll(s.c_str());
    cout << num << endl;
    // exit(0);
    // cout << power(2, 1000000000, 1000000007) << endl;
    // cout << _power(10, 3, 10) << endl;  
}

signed main() {
    solve();
    akitama;
}