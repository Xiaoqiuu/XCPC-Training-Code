#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = INT_MAX;
    while (l < r) {
        ll mid = (l + r) >> 1;
        ans = 0;
        bool flag = false;
        for (int i = 0; i < n; ++ i) {
            if (a[i] <= mid) continue;
            if (s[i] == 'R') flag = false;
            else if(!flag) { ans++; flag = true; }
        }
        if (ans <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ans = r;
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    return 0;
}
