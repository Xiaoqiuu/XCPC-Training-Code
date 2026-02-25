#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;

#define akitama return 0

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

constexpr int P = 998244353;
vi g[N];
ll a[N], d[N], s[N], df[N], rk[N], c[N], iv[N];
int tim;

void dfs(int u, int p, int dp) {
    d[u] = dp;
    s[u] = 1;
    df[u] = ++tim;
    rk[tim] = u;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, dp + 1);
            s[u] += s[v];
        }
    }
}

void solve() {
    ll n, k;
    if (!(cin >> n >> k)) return;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    tim = 0;
    dfs(1, 0, 0);
    iv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        iv[i] = (ll)(P - P / i) * iv[P % i] % P;
    }
    c[0] = 1;
    ll km = k % P;
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] * (km + i - 1) % P * iv[i] % P;
    }
    for (int i = 1; i <= n; ++i) {
        ll res = 0;
        int L = df[i], R = df[i] + s[i];
        for (int j = L; j < R; ++j) {
            int v = rk[j];
            res = (res + a[v] * c[d[v] - d[i]]) % P;
        }
        cout << res << (i == n ? "" : " ");
    }
    cout << "\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}