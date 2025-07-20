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
Date: 2025-07-20 00:11:50
Akitama Default Contest Template V2.0
*/

// #define vi vector<int>
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

struct P{ int x, y, i; };

int dis(P a, P b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].x >> a[i].y;
        a[i].i = i + 1;
    }
    vector<pii> out;
    set<int> vis;

    while ((int)vis.size() < n) {
        int mx = -1;
        int u = -1, v = -1;
        for (int d = 0; d < 4; ++ d) {
            int ma = INT_MIN, mi = INT_MAX;
            int ui = -1, vi = -1;
            for (int i = 0; i < n; ++ i) {
                if (vis.count(i)) continue;
                int val = 0;
                if (d==0) val = a[i].x + a[i].y;
                if (d==1) val = a[i].x - a[i].y;
                if (d==2) val = -a[i].x + a[i].y;
                if (d==3) val = -a[i].x - a[i].y;
                if (val > ma) ma = val, ui = i;
                if (val < mi) mi = val, vi = i;
            }
            if (ui != -1 && vi != -1) {
                int d = dis(a[ui], a[vi]);
                if (d > mx || (d == mx && make_pair(a[ui].i, a[vi].i) < make_pair(a[u].i, a[v].i))) {
                    mx = d;
                    u = ui;
                    v = vi;
                }
            }
        }  
        vis.insert(u);
        vis.insert(v);
        out.emplace_back(a[u].i, a[v].i);
    }
    for (auto p : out) cout << p.fi << " " << p.se << "\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
