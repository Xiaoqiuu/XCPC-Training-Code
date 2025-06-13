#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
typedef long long ll;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, arr[MAX_N];
        ll prefixSum[MAX_N] = {0};
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        map<ll, int> sumMap;
        int lastPos[MAX_N] = {0};
        sumMap[0] = 0;

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
            if (sumMap.count(prefixSum[i])) {
                lastPos[sumMap[prefixSum[i]] + 1] = i;
            }
            sumMap[prefixSum[i]] = i;
        }

        int dp[MAX_N] = {0};

        for (int i = n; i >= 1; i--) {
            dp[i] = (i == n) ? 0 : dp[i + 1];
            int pos = lastPos[i];
            if (pos && pos <= n) {
                dp[i] = max(dp[i], dp[pos + 1] + 1);
            }
        }

        cout << dp[1] << endl;
    }

    return 0;
}
