#include <bits/stdc++.h>
#define Loop(x,l,r) for (ll x = (l); x < (ll)(r); ++x)
#define LoopR(x,l,r) for (ll x = (r)-1; x >= (ll)(l); --x)
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll , ll > pll;
using namespace std;
 
const int N = 6*1024;
const int mod = 998244353;
int inv[N];
 
ll pw(ll x, ll y)
{
	ll a = 1;
	while (y) {
		if (y&1)
			a = a*x % mod;
		x = x*x % mod;
		y /= 2;
	}
	return a;
}
 
int par[N], height[N];
 
void make_tree(int l, int r, int p, int h)
{
	if (l == r)
		return;
	int m = (l + r)/2;
	par[m] = p;
	height[m] = h;
	make_tree(l, m, m, h+1);
	make_tree(m+1, r, m, h+1);
}
 
int get(int l, int r, int i)
{
	if (l == r)
		return -1;
	int m = (l + r)/2;
	int x;
	if (i <= m) {
		x = get(l, m, i);
	} else {
		x = get(m+1, r, i);
	}
	if (x == -1)
		return m;
	return x;
}
 
int n;
 
ll cnt1(int p, int i, int k)
{
	ll ans = inv[n];
	for (int v = i; v != -1; v = par[v]) {
		ans %= mod;
		if (v < p) {
			ans *= inv[n];
			ans %= mod;
			ans *= k;
		} else if (v > p) {
			ans *= inv[n];
			ans %= mod;
			ans *= n-k;
		}
		ans %= mod;
	}
	return ans;
}
 
ll cnt1r(int x, int k)
{
	ll ans = cnt1(x, get(0, n-1, x), k);
	//cerr << "cnt1 " << x << ' ' << k << " = " << ans << '\n';
	return ans;
}
 
bool anc(int v, int a)
{
	while (v != -1) {
		if (v == a)
			return 1;
		v = par[v];
	}
	return 0;
}
 
ll cnt2(int p1, int i1, int k1, int p2, int i2, int k2)
{
	ll ans = anc(i1, p2)? inv[n-k1]: inv[n];
	while (height[i1] > height[i2])
		i1 = par[i1];
	//while (height[i1] < height[i2])
	//	i1 = par[i1];
	for (int v = i2; v != -1; v = par[v]) {
		while (height[i1] > height[v])
			i1 = par[i1];
		if (i1 == v) {
			if (v > p2) {
				ans *= inv[n-k1];
				ans %= mod;
				ans *= n-k2;
			} else if (p1 < v && v < p2) {
				ans *= inv[n-k1];
				ans %= mod;
				//ans *= k1..k2;
				ans *= (k2-k1);
			}
		} else {
			if (v < p2) {
				ans *= inv[n];
				ans %= mod;
				ans *= k2;
			} else if (v > p2) {
				ans *= inv[n];
				ans %= mod;
				ans *= n-k2;
			}
		}
		ans %= mod;
	}
	return ans;
}
 
ll cnt2r(int x1, int k1, int x2, int k2)
{
	ll ans = cnt2(x1, get(0, n-1, x1), k1, x2, get(0, n-1, x2), k2);
	//cerr << "cnt2 " << x1 << ' ' << k1 << ' ' << x2 << ' ' << k2 << " = " << ans << '\n';
	return ans;
}
 
void solve()
{
	int m;
	cin >> n >> m;
	make_tree(0, n-1, -1, 0);
	vector<pii> vec;
	int bad = 0;
	Loop (i,0,m) {
		int x, k;
		cin >> x >> k;
		x--; k--;
		if (x != 0 && k == 0) {
			bad++;
			continue;
		}
		vec.push_back({x, k});
	}
	if (n == 1) {
		cout << "0 1\n";
		return;
	}
	m = vec.size();
	sort(vec.begin(), vec.end());
	vector<ll> sz(m), cnt(m);
	int mx = 0;
	Loop (i,0,m) {
		sz[i] = 1;
		Loop (j,0,i) {
			if (vec[j].second < vec[i].second)
				sz[i] = max(sz[i], 1 + sz[j]);
		}
		mx = max<int>(mx, sz[i]);
	}
	Loop (i,0,m) {
		if (sz[i] == 1) {
			cnt[i] = cnt1r(vec[i].first, vec[i].second);
			continue;
		}
		cnt[i] = 0;
		Loop (j,0,i) {
			if (vec[j].second >= vec[i].second)
				continue;
			if (sz[j] + 1 != sz[i])
				continue;
			ll x = cnt2r(vec[j].first, vec[j].second, vec[i].first, vec[i].second);
			cnt[i] += x * cnt[j];
			cnt[i] %= mod;
		}
	}
	ll ans = 0;
	if (mx == 0)
		ans = 1;
	Loop (i,0,m) {
		if (sz[i] == mx) {
			ans += cnt[i];
			ans %= mod;
		}
	}
	ans *= pw(n, n);
	ans %= mod;
	cout << (m-mx) + bad << ' ' << ans << '\n';
}
 
signed main()
{
	Loop (i,0,N)
		inv[i] = pw(i, mod-2);
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
		solve();
}