#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define akitama return 0
#define ll long long
#define se second
#define fi first

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int _; cin >> _;
	while (_--) {
		int n, m; cin >> n >> m;
		multiset<ll> s;
		
		for (int i = 0; i < n; ++ i) { ll x; cin >> x; s.insert(x); }
		
		vector<ll> b(m), c(m);
		for (int i = 0; i < m; ++ i) cin >> b[i];
		for (int i = 0; i < m; ++ i) cin >> c[i];
		vector<pair<ll,ll>> v(m);
		for (int i = 0; i < m; ++ i) v[i] = {b[i], c[i]};
		
		sort(v.begin(), v.end());
		
        ll ans = 0;

        for (int i = 0; i < m; ++ i) {
            if (v[i].se > 0) {
                ll k = v[i].fi;                
                auto it = s.lower_bound(k);
                if (it != s.end()) {
                    k = max(*it, v[i].se);
                    s.erase(it);
                    s.insert(k);
                    ++ ans;
                }
            }
        }

        for (int i = 0; i < m; ++ i) {
            ll k = v[i].fi;
            if (v[i].se == 0) {
                auto it = s.lower_bound(k);
                if (it != s.end()) {
                    s.erase(it);
                    ++ ans;
                }
            }
        }

        cout << ans << '\n';

		// priority_queue<pair<ll,ll>> pq;
		// int i = 0;
		// ll ans = 0;
		
		// while (!s.empty()) {
		// 	ll mx = *prev(s.end());
		// 	while (i < m && v[i].first <= mx) {
		// 		pq.push({ v[i].second, v[i].first });
		// 		++ i;
		// 	}
		// 	if (pq.empty()) break;
		// 	auto [gc, gb] = pq.top(); pq.pop();
		// 	auto it = s.lower_bound(gb);
		// 	if (it == s.end()) continue;
		// 	ll x = *it;
		// 	s.erase(it);
		// 	++ ans;
		// 	if (gc > 0) s.insert(max(x, gc));
		// }
		// cout << ans << '\n';
	}
	akitama;
}