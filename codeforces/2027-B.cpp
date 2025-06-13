#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using ll = long long;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // dp[i] 表示以 a[i] 结尾的最长非递增子序列的长度
        vector<ll> dp(n, 1);

        // 计算 dp 数组
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < i; ++j) {
                if (a[j] > a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        ll maxLen = 0; // 找到最长非递增子序列的长度
        for (ll i = 0; i < n; ++i) {
            maxLen = max(maxLen, dp[i]);
        }

        // 输出需要删除的最小元素数量
        cout << n - maxLen << endl;
    }
    return 0;
}