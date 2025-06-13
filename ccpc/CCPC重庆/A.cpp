#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0
constexpr int N = 1e5 + 7;
constexpr int MOD = 998244353;
#define vi vector<int>
vi a;
#define int ll

ll limax (ll a, int b) {
    if (a > b) return a;
    else return b;
}

void solve() {
    int n; cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }

    vector<vi> b(2*n, vi(32, 0));
    ll tmp = 0, maxn = 0;
    for (int i = 0; i < n; ++ i) {
        tmp = a[i];
        for (int j = 0; j < n && tmp; ++ j) {
            ll x = tmp & 1;
            tmp >>= 1;
            b[i][j] = x, b[i+n][j] = x;
        }
    }

    for (int i = 0; i < 32; ++ i) {
        int x = 1;
        for (int j = 1; j < 2 * n; ++ j) {
            if (b[j][i] != b[j-1][i]) {
                if (b[j][i] == 1) {
                    int l = 1, r = N;
                    while (l < r) {
                        int mid = (l + r) / 2;
                        int res = (mid + 1) * mid / 2;
                        if (res < x) { l = mid + 1; }
                        else { r = mid; }
                    }
                    maxn = limax(maxn, l);
                }
                x = 0;
            }
            x += 1;
        }
    }
    cout << maxn << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}