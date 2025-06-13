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
void solve() {
    int n; cin >> n;
    // ll a = 0, b = 0;
    vll a(n, 0);
    vll b(2, 0);
    for (int i = 0; i < n ; ++ i) {
        cin >> a[i];
        b[a[i]] ++;
    }
    if (b[0]==n || b[1]==n) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; ++ i) {
        if (a[i] == a[i - 1] && a[i] == 1) continue;
        else if (a[i] != a[i - 1]) continue;
        else {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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