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
	ll n; cin >> n;
	ll rk, ck, rd, cd; cin >> rk >> ck >> rd >> cd;
	if (rk == rd && ck == cd) {
		cout << "0\n";
		return;
	}
	ll dr = llabs(rk - rd), dc = llabs(ck - cd);
//	ll m = max(dr, dc);
//	ll rs;
//	if (rd < rk) rs = n - rk;
//	else if (rd > rk) rs = rk;
//	else rs = max(rk, n - rk);
//	ll cs;
//	if (cd < ck) cs = n - ck;
//	else if (cd > ck) cs = ck;
//	else cs = max(ck, n - ck);
	ll r = (rd < rk) ? (n - rk) : (rd > rk) ? rk : max(rk, n - rk);
	ll c = (cd < ck) ? (n - ck) : (cd > ck) ? ck : max(ck, n - ck);
//	printf("current m : %d rs : %d cs : %d\n", m, rs, cs);
//	cout << (m > rs || m > cs ? rs + cs: m + min(rs, cs)) << endl;
	ll ans;
	if (rk == rd) ans = dc + c;
	else if (ck == cd) ans = dr + r;
	else ans = max(dr + r, dc + c);
	cout << ans << endl;
}

signed main() {
	int _; cin >> _;
	while (_--) {
		solve();
	}
	akitama;
}