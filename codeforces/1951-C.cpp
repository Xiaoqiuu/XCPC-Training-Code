#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

#define akitama return 0

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n+1, 0);
    vector<ll> dp(n, 0);
    // for (auto &i : a) cin >> i;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        dp[i-1] = i;
    }
    sort(dp.begin(), dp.end(), [&](int x, int y) {
        if (a[x] != a[y]) return a[x] < a[y];
        return x < y;
    });
    // for (int i = 1; i <= n; ++ i) {
    //     dp[i] = min(dp[i-1],);
    // }
    ll ans = 0, cnt = 0;
    for (auto x : dp) {
        ll t = min(m, k);
        ans += 1LL * t * (a[x] + cnt);
        cnt += t;
        k -= t;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}