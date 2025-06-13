#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define akitama return 0
#define ll long long int
#define fi first
#define se second

const int N = 1e5 + 7;
int w[N] = { 0 }, v[N] = { 0 };
int f[27][N] = { 0 };

void solve() {
    int n, m; cin >> n >> m;
    // vector<pair<int, int>> wp(m);
    for (int i = 1; i <= m; ++ i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; ++ i) {
        for (int j = 0; j <= n; ++ j) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] = max(f[i][j], f[i-1][j-w[i]]+w[i]*v[i]);
            }
        }
    }
    cout << f[m][n] << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_--) { solve(); }
    akitama;
}