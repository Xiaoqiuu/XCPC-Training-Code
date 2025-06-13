#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <cstdlib>

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
#define vvvi vector<vector<vector<int>>>

const int maxn = 1e6 + 10;
const int N = 350;
vvvi dp(N, vector<vi>(N, vi(N, 0x3f)));
int a[N], b[N];

void solve() {
    int x, y, n; cin >> n >> x >> y;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i] >> b[i]; 
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= x; ++ j) {
            for (int k = 0; k <= y; ++ k) {
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                int tx = min(j + a[i], x), ty = min(k + b[i], y);
                dp[i][tx][ty] = min(dp[i][tx][ty], dp[i-1][j][k-1]);
            }
        }
    }

    if (dp[n][x][y] < maxn) cout << dp[n][x][y] << endl;
    else cout << "-1\n";
    return;
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