/*
 * @Author: Xiaoqiuu xiaoqiuuu@gmail.com
 * @Date: 2025-06-14 20:25:10
 * @LastEditors: Xiaoqiuu xiaoqiuuu@gmail.com
 * @LastEditTime: 2025-06-14 20:33:11
 * @FilePath: /workspace/atcoder/abc410/C.cpp
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
Date: 2025-06-14 20:26:30
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++ i) a[i] = i + 1;
    int shift = 0;
    while (q-- > 0) {
        int t; cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p = ( p + shift - 1) % n;
            a[p] = x;
        } else if (t == 2) {
            int p; cin >> p;
            p = (p + shift - 1) % n;
            cout << a[p] << endl;
        } else {
            int k; cin >> k;
            shift = (shift + k) % n;
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
