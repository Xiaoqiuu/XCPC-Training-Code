#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-31 21:08:55
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

vector<vll> dp(N, vll(2));

ll llmin(ll a, ll b) {
    return (a > b? b : a);
}

void solve() {
    int n; cin >> n;
    // Open 2 consideration dp
    // dp[][1]
    //dp[][0]
    vi num(n+1);
    for (int i = 1; i <= n; ++ i) {
        cin >> num[i];
    }
    vector<string> s(n+1), _s(n+1);
    for (int i = 1; i <= n; ++ i) {
        cin >> s[i];
        _s[i] = s[i];
        reverse(_s[i].begin(), _s[i].end());
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = 0;
    dp[1][1] = num[1];
    for (int i = 2; i <= n; ++ i) {
        if (s[i] >= s[i - 1]) {
            dp[i][0] = dp[i - 1][0];
        }
        if (s[i] >= _s[i - 1]) {
            dp[i][0] = llmin(dp[i][0], dp[i - 1][1]); 
        }
        if (_s[i] >= s[i - 1]) {
            dp[i][1] = num[i] + dp[i - 1][0];
        }
        if (_s[i] >= _s[i - 1]) {
            dp[i][1] = llmin(dp[i][1], dp[i - 1][1] + num[i]);
        }
    }
    ll ans = llmin(dp[n][0], dp[n][1]);
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
