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
Date: 2026-05-23 22:50:51
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
    vll a(n), b(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; ++ i) {
        sum += max(a[i], b[i]);
        mx = max(mx, min(a[i], b[i]));
    }
    cout << sum + mx << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}

// 1 2 3
// 1 -2 3
// -1 2 -3
// 4 4 4 -4 -5

