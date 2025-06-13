//EXGCD
#include <iostream>
//#include <algorithm>

using namespace std;

#define akitama return 0
#define ll long long

int exgcd(int& x, int& y, int a, int b) {
    if(!b) {
        x = 1;
        y = 0;
        return a;
    }
    int t = exgcd(x, y, b, a % b);
    // y = t - a / b * y;
    y -= (a / b) * x;
    return t;
}

void solve() {
    // ax + by = gcd(a, b)
    printf("Enter two integers: \n");
    int a, b;
    cin >> a >> b;
    int x, y;
    exgcd(x, y, a, b);
    cout << "x = " << x << ", y = " << y << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _  = 1;
    while (_) {
        solve();
        _--;
    }

    akitama;
}