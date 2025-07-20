// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// #include <climits>
// #include <utility>
// #include <cmath>
// #include <stack>
// #include <queue>
// #include <iomanip>
// #include <numeric>
// #include <bitset>
// #include <cstdlib>
// #include <set>
// #include <map>
// #include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-19 23:20:56
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

vll x, y;

void solve() {
    int n; cin >> n;
    x.resize(n), y.resize(n);
    for (int i = 0; i < n; ++ i) {
        cin >> x[i] >> y[i];
    }
    vector<array<ll, 4>> f(n);
    // dp
    for (int i = 0; i < n; ++ i) {
        f[i][0] = x[i] + y[i];
        f[i][1] = x[i] - y[i];
        f[i][2] = y[i] - x[i];
        f[i][3] = -x[i] - y[i];
    } 
    array<set<pair<ll, ll>>, 4> s;
    for (int k = 0; k < 4; ++ k) {
        s[k].clear();
        for (int i = 0; i < n; ++ i) {
            s[k].emplace(f[i][k], i);
        }
    }
    for (int i = 0; i < n / 2; ++ i) {
        ll best = -1;
        int best_u = -1, best_v = -1, best_k = -1;
        for (int k = 0; k < 4; ++ k) {
            auto it_l = s[k].begin();
            auto it_h = prev(s[k].end());
            ll d = it_h->fi - it_l->fi;
            if (d > best) {
                best = d;
                best_u = it_l->se;
                best_v = it_h->se;
                best_k = k;
            }
        }
        cout << best_u + 1 << " " << best_v + 1 << endl;
        // delete u v
        for (int k = 0; k < 4; ++ k) {
            s[k].erase( { f[best_u][k], best_u } );
            s[k].erase( { f[best_v][k], best_v } );
        }
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
