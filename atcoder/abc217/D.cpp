#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long int;
using ld = long double;
#define akitama return 0
#define vi vector<int>
#define vll vector<ll>

void solve() {
    ll l, q; cin >> l >> q;
    set<int> se;
    se.insert(0);
    se.insert(l);
    while(q--) {
        int op, x; cin >> op >> x;
        if (op == 1) se.insert(x);
        else if (op == 2) cout << *se.lower_bound(x) - *--se.lower_bound(x) << endl;
    }
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}