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
Date: 2025-07-16 21:55:19
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

// vi fa(N);
vector<vi> adj;

// inline void init(int n) {
//     for (int i = 1; i <= n; ++ i) {
//         fa[i] = i;
//     }
// }

int find(int x) {
    if (fa[x] == x) {
        return x;
    } else {
        return find(fa[x]);
    }
}

inline void merge(int i, int j) {
    fa[find(i)] = find(j);
}

void solve() {
    // 一共有n个房间
    int n; cin >> n;
    adj.resize(n+1);
    vi du(n+1);
    
    // 每个房间最多3扇门
    // 在房间u 通过标号i的门进入的
    // 每个房间走向为标号？
    // 事实上 是每一个房间作为一个节点
    // 每个节点的最多连接3个其它节点
    
    // input
    // 对单边建图
    for (int i = 1; i <= n; ++ i) {
        int d; cin >> d;
        du[i] = d;
        adj[i].resize(d + 1);
        for (int j = 1; j <= d; ++ j) {
            cin >> adj[i][j];
        }
    }

    // 对边进行映射
    unordered_map<ll, int> edge;
    int ec = 0;
    auto check = [&](int x, int y) {
        
    };

}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
