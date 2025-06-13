#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define akitama return 0

const int N = 1e3 + 5;
int f[N][N];

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    a = " " + a;
    b = " " + b;
    f[0][0] = 0;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j - 1]);
        }
    }
    cout << f[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}