#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>

using namespace std;
using ll = long long int;
#define akitama return 0
#define vi vector<int>

vi dp;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) { cout << "1\n"; return; }
    if (n == 2) { cout << "0\n"; return; }
    // dp.resize(n+1, 0);
    // 设置二维dp[i][j]
    // i 表示当前s[i]pos的最小操作次数
    // j : 0 连续相同且个数为偶数的情况
    // j : 1 一对子序列且个数为偶数的情况
    // 设置状态 
    vector<vi> dp(n+3, vi(30, 0)), dp2(n+3, vi(30, 0));
    if (n % 2 == 0) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= 26; ++ j) {
                dp[i][j] = dp[i-1][j];
            }
            if (i % 2) {
                dp[i][s[i-1]-'a'+1]++;
            }
        }
        for (int i = 2;i <= n; ++ i) {
            for (int j = 1; j <= 26; ++ j) {
                dp2[i][j] = dp2[i-1][j];
            } if (i%2==0) {
                dp2[i][s[i-1]-'a'+1]++;
            }
        }
        int maxn = 0, maxm = 0;
        for (int i = 1; i <= 26; ++ i) {
            maxn = max(maxn, dp[n][i]);
            maxm = max(maxm, dp2[n][i]);
        }
        cout << n - maxn - maxm << endl;
        return;
    } else {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= 26; ++ j) {
                dp[i][j] = dp[i-1][j];
            }
            if (i % 2) {
                dp[i][s[i-1]-'a'+1]++;
            }
        }
        for (int i = 2;i <= n; ++ i) {
            for (int j = 1; j <= 26; ++ j) {
                dp2[i][j] = dp2[i-1][j];
            } if (i%2==0) {
                dp2[i][s[i-1]-'a'+1]++;
            }
        }
        int ans = n, maxn = 0, maxm = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= 26; ++ j) {
                maxn = max(maxn, dp[i-1][j]+dp2[n][j]-dp2[i][j]);
                maxm = max(maxm, dp[i-1][j]+dp2[n][j]-dp2[i][j]);
                // ans = min(ans, );
            }
            
        }
        ans = min(ans, n - maxn - maxm);
        cout <<ans<< "\n";
        return;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}