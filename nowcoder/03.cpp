#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
ll a[N][N];

bool dfs(ll a[], int m, int n) {
    int dp[n + 1][m + 1];
    // 初始化dp数组
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    
    // 起点的路径数量设为1
    dp[1][1] = 1;

    // 填充dp数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 不处理起点
            if (i == 1 && j == 1) continue;

            // 从上方和左方累加路径数量
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // 返回从起点 (1, 1) 到终点 (n, m) 的路径数量
    cout << "从(1, 1)到(" << n << ", " << m << ")的路径数量为: " << dp[n][m] << endl;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int m, n;
    cin >> n >> m;
    dfs(a, m, n);
    return 0;
}
