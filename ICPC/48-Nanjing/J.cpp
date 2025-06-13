#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define akitama return 0
//#define int long long

void solve() {
    int n, m, k; cin >> k >> m >> n;
    vi f(n);
    int ans = 0;
    for (int i = 0; i < k; ++ i) {
        int x; cin >> x;
        x --;
        f[x] = 1;
    }

    map<pii, int> edge;
    vi deg(n);
    ll sum = 0;
    for (int i = 0; i < m; ++ i) {
        int x, y; cin >> x >> y;
        x --, y --;
        if (x > y) { swap(x, y); }
        if (f[x] && f[y]) sum ++;
        else if (x == y) deg[x] ++;
        else if (f[x]) deg[y] ++;
        else if (f[y]) deg[x] ++;
        else {
            edge[{x, y}] ++;
        }
    }

    for (auto [u, v] : edge) {
        auto [a, b] = u;
        ans = max(ans, deg[a] + deg[b] + v);
    }

    sort(deg.begin(), deg.end(), greater<>());
    //tmp = ans;
    if (n == 1) {
        ans = max(ans, deg[0]) + sum;
    } else {
        ans = max(ans, deg[0] + deg[1]) + sum;
    }

    cout << ans << endl;
}
signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }

    akitama;
}