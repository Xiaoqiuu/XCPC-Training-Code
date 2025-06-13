// Prim 算法
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
#define ms(a, val) memset(a, val, sizeof(a))
#define akitama return 0
const int N = 550, INF = 0x3f3f3f3f;

int n, m, g[N][N];
int d[N], v[N];

int prim() {
    ms(d, 0x3f);
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        int t = -1;
        for (int j = 1; j <= n; ++ j) {
            if (v[j] == 0 && (t == -1 || d[j] < d[t]))
                t = j;
        }
        v[t] = 1;
        if (i && d[t] == INF) return INF;
        if (i) ans += d[t];
        for (int j = 1; j <= n; ++ j) {
            d[j] = min(d[j], g[t][j]);
        }
    }
    return ans;
}

void solve() {
    ms(g, 0x3f);
    cin >> n >> m;
    while (m--) {
        int x, y, w; cin >> x >> y >> w;
        g[x][y] = g[y][x] = min(g[x][y], w);
    }
    int t = prim();
    if (t == INF) cout << "impossible\n";
    else cout << t << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _  = 1; // cin >> _;
    while (_--) { solve(); }
    akitama;
}