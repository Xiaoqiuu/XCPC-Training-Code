#include <bits/stdc++.h>

signed main() {
	int _; std::cin >> _;
	while (_--){
	int n; std::cin >> n;
	long long ans = 0;
	int cnt = n;
	int l = 0;
	while (cnt >= 2 || l >= 2) {
		int wm = cnt / 2;
		ans += wm;
		cnt -= wm;
		l += wm;
		int lm = l / 2;
		ans += lm;
		l -= lm;
	}
	printf("%lld\n", ans + 1);
	}
}