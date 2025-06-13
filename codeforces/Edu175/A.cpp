#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define akitama return 0

void solve() {
    int n; cin >> n;
    ll ans = n / 15 * 3;
    n %= 15;
    ans += min(3, n + 1);
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    akitama;
}
