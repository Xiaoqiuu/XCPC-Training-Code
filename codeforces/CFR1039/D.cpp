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
Date: 2025-07-28 00:15:49
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
    int n; cin >> n;
    vi p(n);
    for (auto &i : p) cin >> i;

    vll d;
    ll cur = 1;
    for (int i = 0; i < n - 1; ++ i) {
        if (p[i] > p[i + 1]) cur++;
        else {
            d.pb(cur);
            cur = 1;
        }
    }
    d.pb(cur);
    int R = d.size();
    // s0 s1 s2 s3 xk -1/2 x-1/2
    vll s0(R+1,0),s1(R+1,0),s2(R+1,0),s3(R+1,0);
    for (int i = 1; i <= R; ++ i) {
        ll di = d[i - 1];
        ll t = di * (di - 1) / 2;
        s0[i] = s0[i - 1] + di;
        s1[i] = s1[i - 1] + di * (ll)i;
        s2[i] = s2[i - 1] + t;
        s3[i] = s3[i - 1] + t * (ll)i;
    } 

    ll ans = 0;
    for (int i = 0; i <R ; ++ i) {
        ll di = d[i];
        ans += di * (di + 1) * (di + 2) / 6;
    }

    ll tot0 = s0[R], tot1 = s1[R], tot2 = s2[R];
    ll A = 0;
    for (int i = 1; i <= R; ++ i) {
        ll di = d[i - 1];
        ll v = ((ll)i * (i + 1) / 2) - 1;
        A += di * v;
    }
    ll B = 0;
    for (int i = 1; i <= R; ++ i) {
        ll di = d[i - 1];
        ll t = di * (di - 1) / 2;
        B += (ll)(i - 1) * t;
    }
    ll C = 0, D = 0;
    for (int i = 1; i <= R; ++ i) {
        ll di1 = d[i - 1] - 1;
        // ll t = di * (di - 1) / 2;
        // B += (ll)(i - 1) * t;
        if (di1 <= 0) continue;
        ll sumid = tot1 - s1[i];
        ll sumd = tot0 - s0[i];

        C += di1 * (sumid - (ll)i * sumd);
        D += di1 * (tot2 - s2[i]);
    }
    ans += D + C + B + A;
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
