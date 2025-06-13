#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <set>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-27 09:17:13
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

ll llmin(ll a, ll b) {
    if (a < b) return a;
    else return b;
}

void solve() {
    int n; cin >> n;
    vll x(n, 0), y(n, 0);
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; ++ i) {
        cin >> x[i] >> y[i];
        s.emplace(x[i], y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
 
    ll ans = (x[n - 1] - x[0] + 1LL) * (y[n - 1] - y[0] + 1LL);
    auto f = [&](ll h, ll w) {
        ll ans_ = h * w;
        if (ans_ == n - 1)
        ans_ += llmin(h, w);
        ans = min(ans, ans_);
    };
    if (n >= 2) {
        f(x[n-1] - x[1] + 1, y[n - 1] - y[0] + 1);
        f(x[n-1] - x[0] + 1, y[n - 1] - y[1] + 1);
        f(x[n-2] - x[0] + 1, y[n - 1] - y[0] + 1);
        f(x[n-1] - x[0] + 1, y[n - 2] - y[0] + 1);
        if (s.find({x[0], y[0]}) != s.end()) {
            f(x[n-1] - x[1] + 1, y[n - 1] - y[1] + 1);
        }
        if (s.find({x[0], y[n - 1]}) != s.end()) {
            f(x[n-1] - x[1] + 1, y[n - 2] - y[0] + 1);
        }
        if (s.find({x[n - 1], y[0]}) != s.end()) {
            f(x[n-2] - x[0] + 1, y[n - 1] - y[1] + 1);
        }
        if (s.find({x[n-1], y[n-1]}) != s.end()) {
            f(x[n-2] - x[0] + 1, y[n - 2] - y[0] + 1);
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
