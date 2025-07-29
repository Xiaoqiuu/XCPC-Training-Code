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
Date: 2025-07-27 23:32:18
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
    bool ans = 1;
    int n; cin >> n;
    vll a(n);
    for (auto &i : a) cin >> i;
    ll p = a[0];
    for (int i = 1; i < n; ++ i) {
        ll x = a[i];
        p = min(p, a[i - 1]);
        if (x <= p) continue;
        bool f = 0;
        for (int k= 2;; k ++) {
            ll mn = (1LL << k) - 1;
            if (mn > x) break;
            ll mx = p + ((1LL << (k - 1)) - 1);
            if (x >= mn && x <= mx) {
                f = 1;
                break;
            }
        }
        if (!f) {
            ans = 0;
            break;
        }
    }
    cout << ( ans ? "Yes" : "No") << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
