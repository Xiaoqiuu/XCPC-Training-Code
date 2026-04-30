/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-29 18:59:58
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-29 20:24:50
 * @FilePath: /workspace/ICPC/49-Nancang-inv/M.cpp
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
Date: 2026-04-29 19:00:01
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
    if (n == 1) {
        if (k == 1) cout << 1 << endl;
        else cout << 2 << endl;
    } else if (n == 2 && k == 1) {
        cout << "14" << endl;
    }
    else if (k == 0) {
        if (n&1) {
            for (int i = 1; i <= n -1 ;++ i) {
                if (i&1) cout << 1;
                else cout << 3;
            } cout << 4 << endl;
        } else {
            for (int i = 1; i <= n; ++ i) {
                if (i&1) cout << 1;
                else cout << 3;
            }
        }
    }
    else if (k == n) {
        cout << "24";
            for (int i = 3; i <= n ;++ i) {
                if (i&1) cout << 1;
                else cout << 3;
            }
    } else {
        
            for (int i = 1; i <= k; ++ i) {
                cout << 1;
            }
            for (int i = k; i < n; ++ i) {
                cout << 4;
            }
        
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
