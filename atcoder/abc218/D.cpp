#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <cstdlib>
#include <map>

using namespace std;
using ll = long long int;
using ld = long double;
#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

void solve() {
    int q; cin >> q;
    vi x(q), y(q);
    map<pii, bool> mp;
    for (int i = 0; i < q; ++ i) {
        cin >> x[i] >> y[i]; 
        mp[{ x[i], y[i] }] = 1;
    }
    ll ans = 0;
    for (int i = 0; i < q; ++ i) {
        for (int j = i + 1; j < q; ++ j) {
            if (x[i] == x[j] || y[i] == y[j]) continue;
            if (mp[{ x[i], y[j] }] && mp[{ x[j], y[i] }]) ans++;
        }
    }

    cout << (ans >> 1) << endl;

}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}