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
Date: 2025-07-30 10:28:28
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

int n, m;
vector<bool> vis;
vector<vector<int>> adj;

bool check(int u, int v) {
    for (int i = 0; i < adj[u].size(); ++ i) {
        if (adj[u][i] == v) return true;
    }
    return false;
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); ++ i) dfs(adj[u][i]);
}

void solve() {
    cin >> n >> m;
    vis.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i <= m; ++ i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    if (check(1, 3)) cout << "Find." << endl;
    else cout << "Not found qwq." << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
