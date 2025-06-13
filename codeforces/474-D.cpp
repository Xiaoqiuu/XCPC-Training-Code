#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
vector<ll> dp(N,0);
vector<ll> sum(N,0);
int n = 1;
void solve() {
    int t, k; cin >> t >> k;
    while (t--) {
        int l, r; cin >> l >> r;
        if (n >= r) {
            cout << (sum[r] - sum[l-1] + MOD) % MOD << endl;
            continue;
        }
        for (int i = n; i <= r; ++ i) {
            if (dp[i]) continue;
            if (i < k) {
                dp[i] = 1;
            } else if (i == k) {
                dp[i] = 2;
            } else {
                dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
            }
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
        }
        cout << (sum[r]-sum[l - 1] + MOD) % MOD << endl;
        n = r;
    }
    
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}