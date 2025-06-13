#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < n; i++)

const int MOD = 998244353;
const int N = 100005;

int _gcd(int a, int b) {
    if (b == 0) return a;
    return _gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vl d(2 * n), p(2 * n + 1);
    rep(i, n) d[i] = d[i + n] = a[i] - b[i];
    rep(i, 2 * n) p[i + 1] = p[i] + d[i];
    ll ans = LLONG_MAX;
    rep(s, n) {
        ll mx = LLONG_MIN;
        for (int j = s; j <= s + n; j++) mx = max(mx, p[j] - p[s]);
        ans = min(ans, max(0LL, mx));
    }
    cout << (ans == 0 ? 1 : ans) << "\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}
