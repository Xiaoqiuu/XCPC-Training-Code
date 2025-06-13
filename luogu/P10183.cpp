#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define akitama return 0
#define ll long long
#define endl '\n'

vector<ll> mod;

ll _gcd(int n, int m) {
    if (n % m == 0) return m;
    else return _gcd(m, n % m); 
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll ans = -1;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        if (i == 0) ans = a[i];
        else ans = _gcd(ans, a[i]);
    }
    if (ans % 2 == 1) cout << "-1" << endl;
    else cout << ans/2 << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    solve();
    akitama;
}