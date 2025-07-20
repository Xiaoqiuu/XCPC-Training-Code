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
Date: 2025-07-20 16:19:30
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

void solve() {
    // 在x，y 的位置上放置TNT
    // 产生2k+1范围内的爆炸💥
    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n);
    for (auto &i : a) cin >> i;

    vector<vi> f(n + 1, vi(m + 1, 0));

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            f[i + 1][j + 1] = a[i][j] == 'g' ? 1 : 0;
            f[i + 1][j + 1] += f[i][j + 1] + f[i + 1][j] -f[i][j];
        }
    }

    int res = n * m;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (a[i][j] == '.') {
                int x1 = max(0, i - k + 1), x2 = min(n - 1, i + k - 1);
                int y1 = max(0, j - k + 1), y2 = min(m - 1, j + k - 1);
                res = min(res, f[x2 + 1][y2 + 1] - f[x1][y2 + 1] - f[x2 + 1][y1] + f[x1][y1]);
            }
        }
    }
    cout << f[n][m] - res << endl;

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
