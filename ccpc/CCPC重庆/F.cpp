#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    if (a > b) {
        cout << "Win\n";
        return;
    }
    if (a + c > b && b < c) {
        cout << "WIN\n";
        return;
    }
    cout << "nowin\n";
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}