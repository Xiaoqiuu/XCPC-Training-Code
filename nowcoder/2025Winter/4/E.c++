#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define akitama return 0
#define ll long long
#define vl vector<long long>
#define vvl vector<vl>

vvl g, d1, d2, d3, d4;

void solve()
{
    int t, n, m;cin >> n >> m;
    
    g.assign(n, vl(m));
    d1.assign(n, vl(m));
    d2.assign(n, vl(m));
    d3.assign(n, vl(m));
    d4.assign(n, vl(m));

    for (int i = 0; i < n;++ i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    for (int i = 0; i < n;++ i)
        for (int j = 0; j < m; ++j){
            d1[i][j] = g[i][j] + (i > 0 && j > 0 ? d1[i - 1][j - 1] : 0);
            d2[i][j] = g[i][j] + (i > 0 && j + 1 < m ? d2[i - 1][j + 1] : 0);
    }
    for (int i = n - 1; i >= 0;-- i)
        for (int j = 0; j < m; ++j){
            d3[i][j] = g[i][j] + (i + 1 < n && j > 0 ? d3[i + 1][j - 1] : 0);
            d4[i][j] = g[i][j] + (i + 1 < n && j + 1 < m ? d4[i + 1][j + 1] : 0);
    }
    ll res = 0;
    for (int i = 0; i < n;++ i)
        for (int j = 0; j < m;++ j)
            res = max(res, d1[i][j] + d2[i][j] + d3[i][j] + d4[i][j] - 3 * g[i][j]);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (T--) {
        solve();
    }
    akitama;
}
