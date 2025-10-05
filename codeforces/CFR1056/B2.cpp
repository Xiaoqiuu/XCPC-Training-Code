#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define akitama return 0
#define fi first
#define se second

static char check(std::pair<int, int> a, std::pair<int, int> b) {
	int dr = b.fi - a.fi;
	int dc = b.se - a.se;
	if (dr == 0 && dc == 1) return 'R';
	else if (dr == 0 && dc == -1) return 'L';
	else if (dr == 1 && dc == 0) return 'D';
	return 'U';
}

static inline int idx_cal(int r, int c, int n) {
	return (r & 1)? r * n + (n - c - 1) : r * n + c;
}

static inline pair<int, int> re(int idx, int n) {
	int r = idx / n;
	int t = idx % n;
	int c = (r & 1)? (n - t - 1) : t;
	return {r, c};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int _; cin >> _;
	while (_--) {
		int n, k;
		cin >> n >> k;
		ll maxn = 1LL * n * n;
		if ((k & 1) != (maxn & 1)){
			cout << "NO\n"; continue;
		} else cout << "Yes\n";
		
		int cut = (int)(maxn - k);
		for (int r = 0; r < n; ++ r) {
			for (int c = 0; c < n; ++ c) {
				int idx = idx_cal(r, c, n);
				char ch;
				if (idx < cut) {
					int t = (idx ^ 1);
					ch = check({r, c}, re(t,n));
				} else if (idx < (int)maxn - 1) {
					ch = check({r,c}, re(idx+1,n));
				} else {
					ch = 'D';
				}
				cout << ch;
			}
			cout << endl;
		}
	}
	
	akitama;
}