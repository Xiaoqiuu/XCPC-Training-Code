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
Date: 2025-06-12 23:17:11
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

vi a;

void solve() {
    ll n, k; cin >> n >> k;
    vll cost;
    a.resize(n);
    for (auto &i : a) cin >> i;
    ll s = 0;
    for (auto v : a) {
        s += __builtin_popcount(v);
    }
    cost.reserve(40 * n);
    auto check = [&](int x) {
        int t = 0;
        while (x & 1) {
            t++;
            x >>= 1;
        }
        return t;
    };
    for (int v0 : a) {
        int v = v0;
        // ll step = 0;
        for (int t = 0; t <= 60 && v <= v0 + k; ++ t) {
            int t1 = check(v);
            ll d = (ll)t1 + 1;
            v += d;
            if (v > v0 + k) break;
            cost.pb(d);
        }
    }
    sort(cost.begin(), cost.end());
    ll u = 0, g = 0;
    for (auto c : cost) {
        if (u + c > k) break;
        u += c;
        g++;
    }
    cout << s+g << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
