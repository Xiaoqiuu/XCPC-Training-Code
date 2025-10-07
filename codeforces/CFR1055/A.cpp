#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <iomanip>
#include <cctype>
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

void solve() {
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
	}
	
	unordered_set<int> us;
	
	for (auto x : a) if (x > 0) us.insert(x);

	cout << us.size() * 2 - 1 << endl;
}

signed main() {
	int _; cin >> _;
	while (_--) {
		solve();
	}
	akitama;
}