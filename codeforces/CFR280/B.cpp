#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cmath"//;
#include "iomanip"
using namespace std;

typedef long long int ll;
typedef long double ld;
#define akitama return 0

ld ldmax(ld a, ld b) {
    return a > b ? a : b;
}

signed main() {
    int n, len; cin >> n >> len;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    sort(a.begin(), a.end());
    ld ans = 0;
    for (int i = 1; i < n; ++ i) {
        if (i == 1 && a[0] != 0) {
            ans = a[0];
            continue;
        }
        else if (i == n - 1) ans = ldmax(ans, len - a[i]);
        else {
            ans = ldmax(ans, (a[i] - a[i - 1]) / 2.0);
        }
    }
    cout << fixed << setprecision(9);
    cout << ans << endl;

    akitama;
}