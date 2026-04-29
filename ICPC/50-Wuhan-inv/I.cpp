/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-28 20:05:09
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-28 20:37:32
 * @FilePath: /workspace/ICPC/50-Wuhan-inv/I.cpp
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
Date: 2026-04-28 20:05:14
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
    int n, k; cin >> n >> k;
    if (k < n || k > n*n-n+1) {
        cout << "No" << endl;
        return;
    } else cout << "Yes" << endl;
    vector<vi> ans(n+1, vi(n+1, 0));
    vector<bool> f(n*n, 0);
    int l = k;
    for (int i = 1; i <= n; ++ i, --l) {
        ans[i][1] = l;
        f[l] = 1;
    }
    int r = n * n;
    for (int i = 2; i <= n; ++ i, -- r) {
        ans[i][i] = r;
        f[r] = 1;
    }

    int num = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (ans[i][j] == 0) {
                while(f[num]) {
                    num++;
                }
                ans[i][j] = num;
                f[num] = 1;
                num++;
            }
        }
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cout << ans[i][j] << " ";
        } cout << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
