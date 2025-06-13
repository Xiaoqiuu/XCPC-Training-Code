#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll combination(ll n, ll k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= min(i, k); ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main() {
    int n, m;
    cin >> n >> m;
    n = (n - 5) / 2 + 2;
    cout << combination(m + n - 1, n - 1) << endl;
    return 0;
}