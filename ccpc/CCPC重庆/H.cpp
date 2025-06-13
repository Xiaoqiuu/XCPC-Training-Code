#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
using ll = long long int;
#define akitama return 0
constexpr int N = 1e5 + 7;
constexpr int MOD = 998244353;
#define vi vector<int>
vi a, b, c;
// #define int ll 

ll limax (ll a, int b) {
    if (a > b) return a;
    else return b;
}

void solve() {
    int n; cin >> n;
    a.resize(n, 0);
    b.resize(n, 0);
    c.resize(n, 0);
    vi a1(n, 0);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < n; ++ i) {
        cin >> b[i];
        b[i] -= 1;
        a1[b[i]] = i;
    }
    for (int i = 0; i < n; ++ i) { 
        cin >> c[i];
    }
    int maxn = INT_MIN, pos = 0;
    for (int i = 0; i < n; ++ i) {
        pos = a[i];
        if (c[i]==1) {
            if (maxn > a1[pos]) {
                cout << "No" << endl;
                return;
            }
            maxn = max(a1[pos], maxn);
        }
    }

    cout << "Yes" << endl;
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}