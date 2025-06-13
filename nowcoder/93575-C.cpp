#include <iostream>
#include <vector>
#include <cmath>
#define akitama return 0
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;


int main() {
    int n, x;cin >> n >> x;
    ll ans = 0;
    vector<int> s;
    for (int i = 1; i * i <= x; ++i) {
        s.push_back(i * i);
    }
    vector<int> dp(x + 1, 0);//dp前缀和数量
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<int> new_dp(x + 1, 0);//dp前缀和数量
        for (int j = 0; j <= x; ++j) {
            if (dp[j] > 0) {
                for (int k : s) {
                    int sum_1 = j + k;
                    if (sum_1 > x) break;//超出x
                    new_dp[sum_1] = (new_dp[sum_1] + dp[j]) % MOD;
                }
            }
        }
        dp.swap(new_dp);
    }
    for (int j = 1; j <= x; ++j) {
        ans = (ans + dp[j]) % MOD;
    } cout << ans << endl;
    akitama;
}

//TLE
/*
int main() {
    int n, x;cin >> n >> x;
    ll ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;//长度0，前缀和0

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (dp[i - 1][j] > 0) {//判断状态
                for (int k = 1; j + k <= x; ++k) {
                    int sum_1 = j + k;
                    if (sum_1 > 0 && sum_1 <= x) {
                        int sqrt_val = sqrt(sum_1);
                        if (sqrt_val * sqrt_val == sum_1) {
                            dp[i][sum_1] = (dp[i][sum_1] + dp[i - 1][j]) % MOD;//完全平方
                        }
                    }
                }
            }
        }
    }
    for (int j = 1; j <= x; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
*/