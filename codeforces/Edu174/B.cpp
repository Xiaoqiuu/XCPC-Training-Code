#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'
#define umii unordered_map<int, int>

/* 
    AKITAMA CODEFORCES EDU174 B SOLUTION 25.2.18 
    TARGET: up to C++23 
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> mat(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    umii mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = mat[i][j];
            if (mp.find(c) == mp.end()) {
                mp[c] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = mat[i][j];
            if (j + 1 < m && mat[i][j + 1] == c) {
                mp[c] = 2;
            }
            if (i + 1 < n && mat[i + 1][j] == c) {
                mp[c] = 2;
            }
        }
    }
    int tot = 0, mx = 0;
    for (auto &p : mp) {
        tot += p.second;
        mx = max(mx, p.second);
    }
    cout << tot - mx << endl;
}

signed main() {
    fast_io;
    int _;
    cin >> _;
    while (_) {
        solve();
        --_;
    }
    akitama;
}



