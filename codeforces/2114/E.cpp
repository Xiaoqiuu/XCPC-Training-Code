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
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-26 23:41:14
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

void solve() {
    int n; cin >> n;
    vll a(n+1), h(n+1), m(n+1);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    vector<vi> g(n+1);
    for (int i = 1, u, v; i < n; ++ i) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi par(n+1, 0);
    vi ord;
    ord.reserve(n);
    queue<int> q;
    q.push(1);
    par[1] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord.pb(u);
        for (int v : g[u]) {
            if (par[v] == 0) {
                par[v] = u;
                q.push(v);
            }
        }
    }
    h[1] = m[1] = a[1];
    for (int i = 1; i < n; ++ i) {
        int u = ord[i], p = par[u];
        ll c1 = a[u];
        ll c2 = a[u] - m[p];
        h[u] = max(c1, c2);
        ll d1 = a[u];
        ll d2 = a[u] - h[p];
        m[u] = min(d1, d2);
    }
    for (int i = 1; i <= n; ++ i) {
        cout << h[i] << (i == n? "\n" : " ");
    }
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
