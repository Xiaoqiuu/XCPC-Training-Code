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
Date: 2025-09-26 13:43:45
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

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100010, MaxM = 500010;
// const int INF = 0x3f3f3f3f;

struct edge {
    int to, dis, next;
} e[MaxM];

int head[MaxN], dis[MaxN], pre[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

inline void add_edge(int u, int v, int d) {
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node {
    int dis, pos;
    bool operator<(const node &x) const {
        return x.dis < dis; // 小根堆
    }
};
priority_queue<node> q;

inline void dijkstra() {
    fill(dis, dis + n + 1, INF);
    fill(pre, pre + n + 1, -1);
    dis[s] = 0;
    q.push((node){0, s});
    while (!q.empty()) {
        node tmp = q.top(); q.pop();
        int x = tmp.pos;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next) {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].dis) {
                dis[y] = dis[x] + e[i].dis;
                pre[y] = x; // 记录路径
                if (!vis[y]) q.push((node){dis[y], y});
            }
        }
    }
}

vector<int> get_path(int t) {
    vector<int> path;
    if (dis[t] == INF) return path; // 不可达
    for (int v = t; v != -1; v = pre[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}


void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++ i) {
        int a, b, w; cin >> a >> b >> w;
        add_edge(a, b, w);
    }

    dijkstra();

    // 
    for (int i = 1; i <= n; ++ i) {
        if (dis[i] != INF) {
            auto path = get_path(i);
            for (auto num : v) cout << num << " ";
            cout << endl;
            return;
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
