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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-28 00:04:45
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define scs(x) scanf("%s", &x)

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

int n, m, k;
vi dx = {0, -1, 0, 1};
vi dy = {-1, 0, 1, 0};

vector<vi> vis;
// vector<vector<char>> c(507, vector<char>(507));
char c[507][507];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++ i) {
        int _x = x + dx[i];
        int _y = y + dy[i];
        if (_x >= 0 && _x < n && _y >= 0 && _y < m && c[_x][_y] == '.' && !vis[_x][_y]) {
            dfs(_x, _y);
        }
    }
    if (k > 0) {
        c[x][y] = 'X';
        k--;
    }
}

void solve() {
    vis.resize(507, vi(507, 0));
    bool flag = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++ i) {
        scs(c[i]);
    }
    for (int i = 0; i < n && !flag; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (c[i][j] == '.') {
                dfs(i, j);
                flag = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%s\n", c[i]);
    }
}

signed main() {
    // cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
