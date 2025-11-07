#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int

signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		vector<ll> a(n);
		
		ll x, mn = LLONG_MAX, mx = LLONG_MIN; 
//		bool f = 0;
		for (auto& i : a) {
			cin >> i;
			mn = min(mn, i);
			mx = max(mx, i);
		}
		cin >> x;
		cout << (x <= mx && x >= mn? "YES" : "NO") << '\n';
	}
}