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
Date: 2025-07-20 20:21:55
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
    bool st[n+10][2];
    vll p(n), d(n);
    for (auto &i : p) cin >> i;
    for (auto &i : d) cin >> i;

    int q; cin >> q;
    
    while (q --) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j <= 1; ++ j) {
                st[i][j] = 0;
            }
        }
        bool direct = -1, flag = 0;
        ll loc, time = 0; cin >> loc;
        while (true) {
            int j = -1;
            if (direct) {
                for (int i = 0; i < n; ++ i) {
                    // T % k  -> time + p[i] - loca
                    if (p[i] >= loc && (time + p[i] - loc) % k == d[i]) {
                        j = i;
                        break;
                    }
                }
            } else {
                for (int i = n - 1; i >= 0; -- i) {
                    if (p[i] <= loc && (time + loc - p[i]) % k == d[i]) {
                        j = i;
                        break;
                    }
                }
            }
            if (j == -1) {
                flag = 1;
                break;
            } else {
                if (st[j][direct]) break;
                st[j][direct] = 1;
                time += abs(p[j] - loc) + 1;
                if (direct) loc = p[j] - 1;
                else loc = p[j] + 1;
                direct ^= 1;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else cout << "No\n";
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
