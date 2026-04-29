/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-29 14:23:03
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-29 14:47:22
 * @FilePath: /workspace/codeforces/CFR1095/A.cpp
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
Date: 2026-04-29 14:23:14
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
constexpr ll MOD = 676767677;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; ++ i) {
        if (a[i] != 1) sum += a[i];
    }
    if (a.back() == 1) sum += 1;
    cout << sum << '\n';

}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
