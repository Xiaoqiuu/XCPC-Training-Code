//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long int;
#define akitama return 0
#define vi vector<int>
const int N = 3E5+7;
int vis[N];
void solve() {
    memset(vis, 0, sizeof(vis));
    int n, m, k; cin >> n >> m >> k;

    vi a(m+1), q(k+1);

    for (int i = 1; i <= m; ++ i) cin >> a[i];
    for (int i = 1; i <= k; ++ i) cin >> q[i];

    if (k == n) {
        for (int i = 0; i < m; ++ i) {
            cout << 1;
        }
    } else if (k == n - 1) {
        ll cnt;
        for (int i = 1; i <= k; ++ i) {
            vis[q[i]] = 1;
        }
        for (int i = 1; i <= n; ++ i) {
            if (vis[i]==0) {
                cnt = i;
                break;
            }
        }
        for (int i = 1; i <= m; ++ i) {
            if (a[i] == cnt) cout << 1;
            else cout << 0;
        }
    } else for (int i = 0; i < m; ++ i) cout << 0;
    cout << "\n";
    
    #undef vi
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) solve();
    akitama;
}