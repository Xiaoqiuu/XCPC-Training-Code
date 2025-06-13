#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define fast_io ios::sync_with_stdio(false),cin.tie(nullptr)
#define endl '\n'

void solve() {
    ll ans = 0;
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> mp;

    while(m --) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        if (x == y) ans ++;
        else mp[make_pair(x, y)] ++;
    }
    for (auto [x, y] : mp) ans += y - 1;

    cout << ans << endl;
}

signed main(){
    fast_io;
    int _ =1;
    // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}