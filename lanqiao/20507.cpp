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
Date: 2026-04-10 17:38:50
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

vector<vi> dp(505, vi(1005, 0));
void solve() {
    int n, m; cin >> n >> m;
    vi a(n + 1, 0);
    vi b(m + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++ i) {
        cin >> b[i];
    }
    // dp[i][h]表示i根甘蔗最后一根为h时所砍的甘蔗数量
    // dp[i][h] = min{dp[i-1][K]} + cost
    // k \in {h\pm b_1, b \ pm b_2, ... b_m}
    // 7 + 2 9
    // 7 - 2 5
    // 7 + 3 10
    // 7 - 3 4
    //min({dp[i-1][9], dp[i-1][5], ..., dp[i-1][4]})
    // 初始值设置为INF
    // 如何去B组里找到适合的高度
    for (int i = 0; i < a[1]; ++ i) {
        dp[1][i] = 1;
    }
    int cost = INT_MIN;
    for (int i = 2; i <= n; ++ i) {
        for (int j = 0; j <= a[i]; ++ j) {
            cost = n + 5;
            for (int k = 1; k <= m; ++ k) {
                if (b[k] <= j && j - b[k] <= a[i-1]) {
                    cost = min(dp[i-1][j - b[k]] + 1, cost);
                }
                if (a[i-1] >= b[k] + j) {
                    cost = min(cost, dp[i-1][j+b[k]] + 1);
                }
            }
            if (cost > n) dp[i][j] = n + 5;
            else {
                if (a[i] == j) --cost;
                dp[i][j] = cost;
            }
        }
    }
    int ans = n + 5;
    for (int i = 0; i <= a[n]; ++ i) {
        ans = min(ans, dp[n][i]);
    }
    if (ans > n) cout << "-1";
    else cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
