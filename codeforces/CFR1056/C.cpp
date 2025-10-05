#include <bits/stdc++.h>
using namespace std;
#define akitama return 0
#define ll long long int
#define vi vector<int>

constexpr ll MOD = 676767677;

bool _start(const vi& a, int start) {
	int n = (int)a.size() - 1;
	vi d(n);
	for (int i = 1; i < n; ++ i) {
		d[i] = a[i + 1] - a[i];
		if (d[i] < -1 || d[i] > 1) return false;
	}
	vi s(n + 1, -1);
	s[1] = start;
	for (int i = 1; i < n; ++ i) {
		if (d[i] == 0) {
			if (s[i] == -1) return false;
			int need = 1 - s[i];
			if (s[i + 1] != -1 && s[i + 1] != need) return false;
			s[i + 1] = need;
		} else if (d[i] == 1) {
			if (s[i] != -1 && s[i] != 0) return false;
			s[i] = 0;
			if (s[i + 1] != -1 && s[i + 1] != 0) return false;
			s[i + 1] = 0;
		} else {
			if (s[i] != -1 && s[i] != 1) return false;
			s[i] = 1;
			if (s[i + 1] != -1 && s[i + 1] != 1) return false;
			s[i + 1] = 1;
		}
	}
	int totr = 0;
	for (int i = 1; i <= n; ++ i) {
		totr += (s[i] == 1? 1 : 0);
	}
	int a1 = totr + (s[1] == 0 ? 1 : 0);
	return a1 == a[1];
}

signed main() {
	int _; cin >> _;
	while(_--) {
		int n; cin >> n;
		vi a(n + 1);
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i];
		}
		ll ans = 0;
		if (_start(a, 0)) ans = (ans + 1) % MOD;
		if (_start(a, 1)) ans = (ans + 1) % MOD;
		cout << ans % MOD << '\n';
	} 
	akitama;
}