#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long int;
using ld = long double;
#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

ll llmin(ll a, ll b)
{
    if (a < b) return a;
    else return b;
}

ll check(ll x) {
    if (x <= 1) return 0;
    return 64 - __builtin_clzll(x - 1);
}

void solve() {
    ll n, m, a, b; cin >> n >> m >> a >> b;
    ll suma = llmin(a, n + 1 - a);
    ll sumb = llmin(b, m + 1 - b);
    ll ans1 = 1 + check(m) + check(suma);
    ll ans2 = 1 + check(n) + check(sumb);
    cout << llmin(ans1, ans2) << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}