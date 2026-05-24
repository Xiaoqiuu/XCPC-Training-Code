/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-23 22:47:02
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-23 22:48:14
 * @FilePath: /workspace/codeforces/CFR1100/A.cpp
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
Date: 2026-05-23 22:47:04
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
    ll n; cin >> n;
    ll mx = -1, mn = INF;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << (mx - mn + 1) / 2 << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
