#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-26 20:44:59
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
// constexpr int INF = 0X3f3f3f3f;
const ll INF = 4e18;

void solve() {
    int n, m; cin >> n >> m;
    ll ds[500][500];
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j) {
            ds[i][j] = i == j? 0 : INF;
        }
    int u, v;
    ll c;
    for (int i = 0; i < m; ++ i) {
        cin >> u >> v >> c;
        // --ds[][]
        u--;
        v--;
        ds[u][v] = min(ds[u][v], c);
        ds[v][u] = min(ds[v][u], c);
    }
    ll K, T;
    vi ap;
    cin >> K >> T;
    for (int i = 0; i < K; ++ i) {
        cin >> u; u--;
        for (auto w : ap) {
            ds[u][w] = min(ds[u][w], T);
            ds[w][u] = min(ds[w][u], T);
        }
        ap.pb(u);
    }

    for (int k = 0; k < n; ++ k){
        for (int i = 0; i < n; ++ i) {
            if (ds[i][k] < INF) {
                for (int j = 0; j < n; ++ j) {
                    if (ds[k][j] < INF) {
                        ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
                    }
                }
            }
        }
    }
    ll du[500], dv[500];
    int qu; cin >> qu;
    while(qu --) {
        int op; cin >> op;
        if (op == 1) {
            cin >> u >> v >> c;
            u--;
            v--;
            for (int i = 0; i < n; ++ i) {
                du[i] = ds[i][u] + c;
                dv[i] = ds[i][v] + c;
            }
            for (int i = 0; i < n; ++ i) {
                ll dui = du[i], dvi = dv[i];
                if (dui >= INF && dvi >= INF) continue;
                ll *dsi = ds[i];
                for (int j = 0; j < n; ++ j) {
                    ll d1 = dui + ds[v][j];
                    ll d2 = dvi + ds[u][j];
                    ll mn = d1 < d2 ? d1 : d2;
                    if (mn < dsi[j]) dsi[j] = mn;
                }
            }
            ds[u][v] = min(ds[u][v], c);
            ds[v][u] = min(ds[v][u], c);
            // for (int p = 0; p < n; ++ p) {
            //     for (int q = 0; q < n; ++ q) {
            //         ll d1 = ds[p][u] + ds[v][q] + c;
            //         ll d2 = ds[u][q] + ds[p][v] + c;
            //         ll mn = min(d1, d2);
            //         if (mn < ds[p][q]) ds[p][q] = mn;
            //     }
            // }
        } else if (op == 2) {
            cin >> u; u --;
            for (auto w : ap) {
                // for (int i = 0; i < n; ++ i) {
                //     du[i] = min(ds[i][u], ds[i][w] + T);
                //     dv[i] = min(ds[i][w], ds[i][u] + T);
                // }
                // for (int i = 0; i < n; ++ i) {
                //     ll dui = du[i], dvi = dv[i];
                //     if (dui >= INF && dvi >= INF) continue;
                //     ll *dsi = ds[i];
                //     for (int j = 0; j < n; ++ j) {
                //         ll d1 = dui + ds[w][j];
                //         ll d2 = dvi + ds[u][j];
                //         ll mn = d1 < d2 ? d1 : d2;
                //         if (mn < dsi[j]) dsi[j] < mn;
                //     }
                // }
                for (int p = 0; p < n; ++ p) {
                    for (int q = 0; q < n; ++ q) {
                        ll d1 = ds[p][u] + ds[w][q] + T;
                        ll d2 = ds[u][q] + ds[p][w] + T;
                        ll mn = min(d1, d2);
                        if (mn < ds[p][q]) ds[p][q] = mn;
                    }
                }

                ds[u][w] = min(T, ds[u][w]);
                ds[w][u] = min(T, ds[w][u]);
            }
            ap.pb(u);
        } else {
            ll ans = 0;
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    if (ds[i][j] < INF) ans += ds[i][j];
                }
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
