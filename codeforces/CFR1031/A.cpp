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
Date: 2025-06-15 16:59:33
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

ll llmax(ll a, ll b) {
    return (a > b? a : b);
}

ll get(ll k, ll need, ll d) {
        if (k < need) akitama;
        return (k - need) / d + 1;
    }

void solve() {
    ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;
    ll res = 0;
    
    if (x < y) {
        ll c1 = get(k, a, x);
        ll k2 = k - c1 * x;
        ll c2 = get(k2, b, y);
        res = c1 + c2;
    } else {
        ll c2 = get(k, b, y);
        ll k2 = k  - c2 * y;
        ll c1 = get(k2, a, x);
        res = c1+c2;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
