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
Date: 2025-06-15 17:42:50
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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> mat;
vector<vector<int>> pre;

int get(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    mat.clear();
    pre.assign(n + 1, vector<int>(m + 1, 0));
    mat.resize(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        int add = (mat[i][j] == 'g');
        tot += add;
        pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + add;
    }

    int out = INT_MAX;
    int r = k - 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (mat[i][j] != '.') continue;
        int x1 = max(0, i - r), y1 = max(0, j - r);
        int x2 = min(n - 1, i + r), y2 = min(m - 1, j + r);
        int cnt = get(x1, y1, x2, y2);
        out = min(out, cnt);
    }

    cout << tot - out << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}