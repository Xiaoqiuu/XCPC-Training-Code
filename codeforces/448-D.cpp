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
Date: 2025-11-07 15:42:59
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
    ll n, m, k; cin >> n >> m >> k;
    ll l = 0, r = n * m;

    ll ans = -1;

    while (l <= r) {
        ll mid = ((l + r) >> 1);
        ll sum = 0;
        for (int i = 1; i <= n; ++ i) {
            sum += min(m, (mid - 1) / i);
        }
        if (sum < k) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
