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
Date: 2025-07-19 16:11:15
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
// vi dp;

void solve() {
    int n, k; cin >> n >> k;
    // dp.resize(n+1, 0);
    a.resize(n, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    // dp[i] = dp[i - 1] + "1? 0 : 1"
    // dp[0] = a[0];
    for (int i = 0; i < n; ++ i) {
        if (a[i] == 1) continue;
        int li = i + 1;
        while (li < n && a[li] == a[i]) li++;
        ans += (li - i + 1) / (k + 1);
        i = li - 1;
    }
    cout << ans << endl;
}

// dp

// void solve1() {
//     int n, k; cin >> n >> k;
//     a.resize(n);
//     for (auto &i : a) cin >> i;
//     vi pre(n + 1, 0);

//     for (int i = 1; i <= n; ++ i) {
//         pre[i] = pre[i - 1] + a[i - 1];
//     }
// }

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
