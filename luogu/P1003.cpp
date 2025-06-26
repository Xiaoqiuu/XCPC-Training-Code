#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define returm(x) return x

constexpr int N = 210;

int n, m, a, b;
bool vis[N][N];
const int x[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int y[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int dp[N][N];

signed main() {
    memset(vis, 1, sizeof(vis));
    cin >> n >> m >> a >> b;
    n += 2, m += 2, a += 2, b += 2;
    for (int i = 1; i <= 8; ++ i) {
        vis[a+x[i]][b+y[i]] = 0; // 标记
    }
    vis[a][b] = 0;
    dp[2][1] = 1;
    for (int i = 2; i <= n; ++ i) {
        for (int j = 2; j <= m; ++ j) {
            if (vis[i][j]) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[n][m] << endl;
    returm(0);
}