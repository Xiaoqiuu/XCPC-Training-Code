#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double

#define akitama return 0

void solve() {
    ll a, b, c, k; cin >> a >> b >> c >> k;
    if(a==b && a==c) {
        cout << a << " " << b << " " << c << endl;
        return;
    }
    ll ta = a, tb = b, tc = c;
    while (k --) {
        a = (ll)(tb + tc)/2;
        b = (ll)(ta + tc)/2;
        c = (ll)(ta + tb)/2;
        ta = a, tb = b, tc = c;
    }
    cout << a << " " << b << " " << c << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}