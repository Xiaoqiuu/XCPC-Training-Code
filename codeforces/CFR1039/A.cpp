/*
 * @Author: Xiaoqiuu xiaoqiuuu@gmail.com
 * @Date: 2025-07-27 22:35:20
 * @LastEditors: Xiaoqiuu xiaoqiuuu@gmail.com
 * @LastEditTime: 2025-07-27 22:36:33
 * @FilePath: /workspace/codeforces/CFR1039/A.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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
Date: 2025-07-27 22:35:27
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
    int n, c; cin >> n >> c;
    vi a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end(), [](auto &x, auto &y){
        return x > y;
    });
    int cnt = 1;
    ll ans = 0;
    for (auto &i : a) {
        if(i * cnt > c) ans++;
        else {
            // ans++;
            cnt *= 2;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
