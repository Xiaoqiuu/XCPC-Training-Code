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
Date: 2025-07-22 22:52:52
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

const int P[4] = { 2, 3, 5, 7 };

ll check(ll n) {
    ll res = 0;
    for (int i = 0; i < (1 << 4); ++ i) {
        // mask ? >= 0 +floor(n)
        ll p = 1;
        ll bits = 0;
        for (int j = 0; j <= 3; ++ j) {
            if (i & (1 << j)) {
                p *= P[j];
                bits++;
            }
        }
        if (p > n) continue;
        ll tmp = n / p;
        if (bits & 1) res -= tmp;
        else res += tmp;
    }
    return res;
}

void solve() {
    ll a, b; cin >> a >> b;
    cout << check(b) - check(a-1) << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
