/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-26 16:47:03
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-26 17:41:09
 * @FilePath: /workspace/codeforces/2209/D.cpp
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
Date: 2026-04-26 16:47:08
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
    string ans = "";
    vector<pair<char, int>> vp = {{'R', 0}, {'G', 0}, {'B', 0}};
    // ll r, g, b; cin >> r >> g >> b;
    cin >> vp[0].se >> vp[1].se >> vp[2].se;
    while (true) {
        sort(vp.begin(), vp.end(), [](auto a, auto b){
            return a.se > b.se;
        });
        // grgrgbgbgbg
        bool ok = 0;

        for (int i = 0; i <= 2; ++ i) {
            char c = vp[i].fi;
            if (vp[i].se == 0) continue;
            if (!ans.empty() && ans.back() == c) continue;
            if (ans.size() >= 3 && ans[ans.size() - 3] == c) continue;
            ans.pb(c);
            --vp[i].se;
            ok = 1;
            break;
        }
        if (!ok) break;
        // if (vp[1].se == 0 && vp[2].se == 0) {
        //     cout << vp[0].fi << endl;
        //     return;
        // }
        // int i = 2;
        // int num = INT_MIN;
        // if (vp[1].se > 0 && vp[2].se > 0 && vp[1].se == vp[2].se) {
        //     // cout << vp[0].fi;
        //     cout << vp[1].fi;
        //     num = --vp[1].se;
        //     // --vp[0].se;
        // } else if (vp[1].se > 0 && vp[2].se > 0 && vp[1].se > vp[2].se) {
        //     cout << vp[0].fi;
        //     cout << vp[1].fi;
        //     num = --vp[1].se;
        //     --vp[0].se;
        // }
        // char ch;
        // if (vp[i].se == 0) {
        //         vp.pop_back();
        //         --i;
        //     }
        // while (vp.size() > 1 && vp[0].se > 0) {
        //     ch = vp[i].fi;
        //     cout << vp[0].fi << vp[i].fi;
        //     --vp[0].se, --vp[i].se;
        //     if (vp[i].se == 0) {
        //         vp.pop_back();
        //         --i;
        //     }
        // }
        // if (vp[1].se == num && vp[1].se != 0) {
        //     cout << vp[1].fi;
        //     ch = vp[1].fi;
        // }
        // if (vp[0].se > 0 && ch != vp[0].fi) {
        //     cout << vp[0].fi;
        // }
        // cout << endl;
    } cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
