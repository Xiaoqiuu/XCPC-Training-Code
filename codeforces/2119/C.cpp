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

using i128 = __int128;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-05 22:59:48
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
    ll aki = 0;
    ll n, l, r, k; cin >> n >> l >> r >> k;
    // 3 1 3 3
    // 0000010
    // 0000001
    if (n & 1) {
        cout << l << endl;
        return;
    }
    if (n == 2) { cout << -1 << endl; return; }
    // ll aki = 0;
    ll tmp = l;
    while (tmp > 1) {
        tmp >>= 1;
        aki++;
    }
    i128 v = (i128)1 << (aki + 1);
    if (v > r) {
        cout << -1 << endl;
        return;
    }
    ll vv = (ll)v;
    // 1000000000000000000
    // 0999999999999999999
    if (k <= n - 2) {
        cout << l << endl;
    } else {
        cout << vv << endl;
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
