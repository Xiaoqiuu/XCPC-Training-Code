#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
using ll = long long int;

void solve() {
    int n; cin >> n;
    vector<int>a(n);
    for (int &i : a) cin >> i;
    stable_sort(a.begin(), a.end());
    bool f = 1;
    for (int i = 1; i < n; ++ i) {
        if (a[i] != a[0]) {
            f = 0;
            break;
        }
    }
    if (f) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ ;cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}