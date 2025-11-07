#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int
#define pb push_back

constexpr int N = 60;

signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int _; cin >> _;
	while (_--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto& i : a) cin >> i;
        if (a[0] == 1) {
            if (n >= 2) { cout << 1 << " " << a[1] << endl; continue; }
        }

        vector<ll> ev;
        for (auto v : a) if ((v & 1LL) == 0) ev.pb(v);
        if ((int)ev.size() >= 2) {
            cout << ev[0] << " " << ev[1] << endl; continue;
        }

        vector<ll> cnt;
        for (int i = 0; i < n && i < N; ++ i) cnt.pb(a[i]);
        for (int i = max(N, 0); i < n; ++ i) {
            if (i >= n - N) cnt.pb(a[i]);
        }
        sort(cnt.begin(), cnt.end()); cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
        bool f = 0;
        ll ans1 = -1, ans2 = -2;
        for (auto x : cnt) {
            int idx = int(lower_bound(a.begin(), a.end(), x) - a.begin()) + 1;
            for (int j = idx; j < n; ++ j) {
                ll y = a[j];
                if (((y % x) & 1LL) == 0) { ans1 = x, ans2 = y, f = 1; break; }
            }
            if (f) break;
        }
        if (!f) cout << "-1\n"; else cout << ans1 << " " << ans2 << endl;
    }
    akitama;
}