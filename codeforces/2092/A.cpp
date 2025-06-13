#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define akitama return 0
#define ll long long int
#define vl vector<ll>
#define pb push_back

void solve() {
    int n; cin >> n;
    vl a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    // d
    cout << a[n-1] -a[0] << endl;
    // 1 10 11
    // 1 2 3 4 5
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    // cout << __gcd(10, 5) << endl;
    akitama;
}