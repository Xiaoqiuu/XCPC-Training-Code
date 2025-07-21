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
Date: 2025-07-22 02:30:57
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

vi x, h;
vector<vi> dp;


void solve() {
    int n; cin >> n;
    x.resize(n + 1, INT_MAX);
    h.resize(n);
    // dp.resize(n+1, vi(2, 0)) // 0 left 1 right
    for (int i = 0; i < n; ++ i) {
        cin >> x[i] >> h[i];
    }
    ll ans = 1;
    int pos = 0;
    for (int i = 1; i < n; ++ i) {
        if (x[i - 1] + pos < x[i] - h[i]) {
            ans += 1;
            pos = 0;
        } else if (x[i] + h[i] < x[i + 1]) {
            ans += 1;
            pos = h[i];
        } else pos = 0;
    } 
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
