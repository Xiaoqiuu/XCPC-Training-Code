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
Date: 2025-07-22 23:11:42
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
constexpr int M = 998244353;
constexpr int INF = 0X3f3f3f3f;

vll dp;

ll quickpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) {
            r = r * a % M;
        } a = a * a % M;
        b >>= 1;
    }
    return r;
}

ll check(ll a) {
    return quickpow(a, M-2);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> bucket(m+1);
    ll cnt = 1;
    for (int i = 0; i < n; ++ i) {
        int l, r;
        ll p, q;
        cin >> l >> r >> p >> q;
        cnt = cnt * (((q - p) % M + M) % M * check(q % M) % M) % M;
        // 1 - p / q -> q - p checek->q mod 998244353
        // Ai -> p / (q - p)
        // [1, m] SS jiaquan 
        ll ai = (p % M) * check(((q - p) % M + M) % M) % M;
        bucket[r].emplace_back(l, ai);
    }   
    dp.resize(m + 10, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; ++ i) {
        ll sum = 0;
        for (auto &p : bucket[i]) {
            ll l = p.fi;
            ll w = p.se;
            sum = (sum + dp[l - 1] * w) % M;
        }
        dp[i] = sum;
    }
    cout << cnt * dp[m] % M << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; //  cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
