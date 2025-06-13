/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-05-30 08:54:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-05-31 20:40:22
 * @FilePath: /workspace/codeforces/2114/F3.cpp
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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-28 19:20:01
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;

vector<vi> g;

int d, x, y, k;

void solve() {
    cin >> x >> y >> k;
    
    auto check = [](int n){
        g.assign(n + 1, {});
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                g[j].pb(i);
            }
        }
    };   
    check();
    
    if (k == 1) {
        cout << (x == y ? 0 : -1) << endl;
        return;
    }

    d = __gcd(x, y);
    x /= d, y /= d;

    auto wrk = [&](int n) -> int {
        int m = g[n].size();
        vi f(m, inf);
        f[0] = 0;
        for (int i = 0; i < m; ++ i) {
            if (f[i] == inf) {
                continue;
            }
            for (int j = i + 1; j < m; ++j) {
                if (g[n][j] % g[n][i] == 0 && g[n][j] / g[n][i] <= k) {
                    f[j] = min(f[j], f[i] + 1);
                } else if (g[n][j] / g[n][i] > k) {
                    break;
                }
            }
        }

        return f[m - 1] == inf ? -1 : f[m - 1];
    };

    int a1 = wrk(x), a2 = wrk(y);
    if (a1 == -1 || a2 == -1) {
        cout << -1 << "\n";
    } else {
        cout << a1 + a2 << "\n";
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