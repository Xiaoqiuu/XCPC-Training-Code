#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

/*
    AKITAMA CODEFORCES EDU174 A SOLUTION 25.2.18
    TARGET: up to C++23
*/

void solve() {
    int n;
    cin >> n;
    vi arr(n - 2);
    for (auto &a : arr) cin >> a;
    bool cur[2][2];
    memset(cur, 0, sizeof(cur));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cur[i][j] = true;
    
    for (int i = 2; i <= n - 1; i++) {
        bool nxt[2][2];
        memset(nxt, 0, sizeof(nxt));
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                if (!cur[x][y]) continue;
                for (int z = 0; z < 2; z++) {
                    int bi = arr[i - 2];
                    if (bi == 1) {
                        if (x == y && y == z) nxt[y][z] = true;
                    } else {
                        if (!(x == y && y == z)) nxt[y][z] = true;
                    }
                }
            }
        }
        memcpy(cur, nxt, sizeof(cur));
    }
    
    bool ok = false;
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            if (cur[x][y]) ok = true;
    
    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    fast_io;
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}