// dp?
// 1e9
// a b
// f(n - 1)!
// qishikeyibuyongzhemekan
//f(n) f(n - 1)

// f(0) f(1) 1 + 1 = 2
 /// /// // // / / / / //// //// //
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
Date: 2025-07-05 23:18:59
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
    ll n, m; cin >> n >> m;
    // vll cnt(n + 1, 0), sumpos(n + 1, 0);
    // vll weight(n + 1, 0);
    // cnt[0] = 1 % m;
    // sumpos[0] = 0;
    // weight[0] = 1 % m;
    // c[k] chuli ( ,k] legal cnt
    vll c(n + 1, 0);
    // s[k] --pos[k]
    vll s(n + 1, 0);
    vll w(n + 1, 0);
    // c[k+1]  = c[k] * (i - k)
    // s[k+ 1]
    c[0] = 1, w[0] = 1; 
    
    auto sum1 = [&](int i) {
        return (ll)i * (i + 1) / 2 % m;
    };
    // cnt[i] before i - 1 -- k(ll k)
    // O(n^2) fuzadu
    // kaiyige  for xunhuan

    for (int i = 1; i <= n; ++ i) {
        vll nc(n + 1, 0), ns(n + 1, 0), nw(n + 1, 0);
        ll tot = sum1(i);
        for (int k = 0; k < i; ++ k) {
            if (c[k] == 0 && w[k] == 0) {
                continue;
            }
            // zhuanyi cunchu
            nc[k] = (nc[k] + c[k]) % m;
            ns[k] = (ns[k] + s[k]) % m;
            nw[k] = (nw[k] + w[k]) % m;
            ll rem = i - k;
            ll sum = (tot - s[k] + m) % m;
            nc[k + 1] = (nc[k + 1] + c[k] * rem) % m;
            ns[k + 1] = (ns[k + 1] + s[k] * rem % m + c[k] * sum % m) % m;
            nw[k + 1] = (nw[k + 1] + w[k] * sum % m) % m;
        }
        swap(c, nc);
        swap(s, ns);
        swap(w, nw); 
    }
    ll ans = 0;
        for (int i = 0; i <= n; ++ i) {
            ans = (ans + w[i]) % m;
            // cout << ans << endl;
        }
        cout << ans % m << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
