#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define akitama return 0
using ll = long long int;
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>

vector<vi> dp(103, vector<int>(3, 0));
bool f1, f2;

void solve() {
    int n; cin >> n;
    vi a(n+1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) {
        int x = a[i];
        f1 = x & 1;
        f2 = x & 2;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        if (f1) dp[i][1] = max(dp[i-1][0], dp[i-1][2])+1;
        if (f2) dp[i][2] = max(dp[i-1][0], dp[i-1][1])+1;
    }
    cout << n - max(max(dp[n][0],dp[n][1]), dp[n][2]) << endl;
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}