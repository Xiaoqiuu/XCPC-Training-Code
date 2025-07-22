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
Date: 2025-07-23 00:13:46
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
    // ll l, r;
    string l, r;
    cin >> l >> r;
    // f(l, x) + f(x, r)
    // 6309 6409
    // 12345
    // 43567
    // if (r[0] - l[0] >= 2) cout << 0 << endl;
    // else 
    // 23577
    // find 23
    // 23647
    int ans = 0;
    // bool f = 1;
    for (int i = 0; i < (int)l.size(); ++ i) {
        if (l[i] == r[i]) ans += 2;
        else if (r[i] - l[i] > 1) {
            cout << ans << endl;
            return;
        } else {
            // l 98999
            //   9990
            // r 99000
            ans++;
            for (int j = i + 1; i < (int)l.size(); ++ j) {
                if (l[j] == '9' && r[j] == '0') ans++;
                else {
                    cout << ans << endl;
                    return;
                }
            }
            break;
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
