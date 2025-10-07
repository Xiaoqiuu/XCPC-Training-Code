#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <iomanip>
#include <cctype>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <climits>
#include <unordered_set>
using namespace std;

#define akitama return 0

using ll = long long int;
using ld = long double;

#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>

void solve() {
	int n, q; cin >> n >> q;
	vi a(n + 1), pre1(n + 1, 0), pre2(n + 1, 0);
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		pre1[i] = pre1[i - 1] + (a[i] == 1? 1 : 0);
		if (i > 1) pre2[i - 1] = pre2[i - 2] + (a[i] == a[i - 1]? 1 : 0);
	}
	pre2[n] = pre2[n - 1];
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		int len = -l + r + 1;
//		printf("current len: %d, l = %d, r = %d\n", len, l, r);
		int cnt = pre1[r] - pre1[l - 1];
		if (len % 3 != 0 || cnt % 3 != 0) cout << "-1\n";
		else {
			int adj = pre2[r - 1] - pre2[l - 1];
			ll ans = len / 3;
			cout << (adj > 0? ans : ans + 1) << endl;
		}
	}
}

signed main() {
	int _; cin >> _;
	while (_--) {
		solve();
	}
	akitama;
}