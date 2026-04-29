/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-28 21:14:09
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-28 21:23:13
 * @FilePath: /workspace/ICPC/50-Wuhan-inv/G.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
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
Date: 2026-04-28 21:14:34
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
vector<vi> a;
void dfs() {

}
// vector<vi> a(n+1, vi(m+1, 0));
void solve() {
    int n, m; cin >> n >> m;
    
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> a[i][j];
        }
    }
    dfs();
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
