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
Date: 2025-06-14 20:33:25
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
#define eb emplace_back

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<vi> adj(n+1);
    for (int i = 0; i < m; ++ i) {
        int a, b, c; cin >> a >> b >> c;
        edges.eb(a, b, c);
        adj[a].pb(i);
    }
    int maxb = 10;
    vi d(n+1, -1);
    d[1] = 0;
    vi st;
    st.pb(1);
    vi vis(n+1);
    vis[1] = 1;
    for (int i = 0; i < (int)st.size(); ++ i) {
        int u = st[i];
        for (auto ei : adj[u]) {
            auto [a, b, c] = edges[ei];
            if (d[b] == -1) {
                d[b] = d[u] ^ c;
                vis[b] = 1;
                st.pb(b);
            }
        }
    }
    if (d[n] == -1) { cout << -1 << endl; return; }
    vi bas;
    for (auto &[u, v, x] : edges) {
        // int u, v, x;
        if (vis[u] && vis[v]) {
            int cx = d[u] ^ x ^ d[v];
            int v0 = cx;
            for (int b : bas) v0 = min(v0, v0^b);
            if (v0 != 0) {
                bas.pb(v0);
                sort(bas.rbegin(), bas.rend());
            }
        }
    }
    int res = d[n];
    for (int b : bas) res = min(res, res^b);
    cout << res;
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
