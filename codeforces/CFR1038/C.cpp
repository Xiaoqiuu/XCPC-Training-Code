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
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-19 22:53:14
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    int n; cin >> n;
    // vector<pair<ll, ll>> a(n);
    vll x(n), y(n);
    for (int i = 0; i < n; ++ i) {
        cin >> x[i] >> y[i];
        // a[i] = { x[i] + y[i], i };
    }
    // // x, y
    // sort(a.begin(), a.end());
    // // min j max j
    // ll ans1, ans2;
    // for (int j = 0; j < n / 2; ++ j) {
    //     ans1 = a[j].se;
    //     ans2 = a[n-j-1].se;
    // cout << ans1+1 << " " << ans2+1 << "\n";
    // }
    auto make_pairs = [&](const vector<ll>& key){
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++ i) {
            a[i] = { key[i], i };
        }
        sort(a.begin(), a.end());
        vector<pair<ll, ll>> pairs;
        pairs.reserve(n / 2);
        for (int i = 0; i < n / 2; ++ i) {
            int u = a[i].se;
            int v = a[n - i - 1].se;
            pairs.emplace_back(u, v);
        }
        return pairs;
    };
    vll u(n), v(n);
    for (int i = 0; i < n ; ++ i) {
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
    }
    auto p1 = make_pairs(u);
    auto p2 = make_pairs(v);

    auto check = [&](const vector<pair<ll, ll>> &p) {
        ll sum = 0;
        for (auto &i : p) {
            int ii = i.fi, jj = i.se;
            sum += llabs(x[ii] - x[jj]) + llabs(y[ii] - y[jj]);
        }
        return sum;
    };

    ll d1 = check(p1);
    ll d2 = check(p2);
    const auto &ans = (d1 >= d2 ? p1 : p2);
    for (auto &p : ans) {
        cout << p.fi+1 << " " << p.se+1 << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
