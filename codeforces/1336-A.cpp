#include <iostream>
#include <string>
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
Date: 2025-11-07 15:16:28
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

constexpr int N = 2e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

basic_string<int> a[N];
vll dep(N), siz(N);
bool vis[N];

ll ans = 0;

void dfs(int x) {
    vis[x] = 1;
    siz[x] = 1;
    for (auto i : a[x]) {
        if (!vis[i]) {
            dep[i] = dep[x] + 1;
            dfs(i);
            siz[x] += siz[i];
        }
    }
}
priority_queue<pair<ll, ll>> pq;

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n - 1; ++ i) {
        ll x, y; cin >> x >> y;
        x--, y--;
        a[x] += y;
        a[y] += x;
    }
    dep[0] = 1;
    dfs(0);
    auto f = [](int x){
        return siz[x] - dep[x];
    };
    pq.push({f(0), 0});
    fill(vis, vis + n, 0);
    for (int i = 0; i < n - k; ++ i) {
        ans += pq.top().fi;
        ll x = pq.top().se;
        pq.pop();
        vis[x] = 1;
        for (auto p: a[x]) {
            if(!vis[p]) pq.push({f(p), p});
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
