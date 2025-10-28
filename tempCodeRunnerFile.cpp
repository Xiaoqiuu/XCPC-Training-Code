#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const long long INF = (long long)4e18;

// DP on a LINE: split v into blocks of size 2 or 3 with minimum L1 cost
static inline long long dp_line(const vector<long long>& v) {
    int m = (int)v.size();
    if (m == 0) return 0;          // nothing left
    vector<long long> dp(m + 5, INF);
    dp[m] = 0;                     // base
    if (m >= 1) dp[m - 1] = INF;   // length 1 is impossible

    for (int i = m - 2; i >= 0; --i) {
        // take a pair (i, i+1)
        dp[i] = min(dp[i], llabs(v[i] - v[i + 1]) + dp[i + 2]);
        // take a triple (i, i+1, i+2)
        if (i + 2 < m) {
            long long mx = max(v[i], max(v[i + 1], v[i + 2]));
            long long mn = min(v[i], min(v[i + 1], v[i + 2]));
            dp[i] = min(dp[i], (mx - mn) + dp[i + 3]);
        }
    }
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        auto seg = [&](int start, int len) {
            vector<long long> v; v.reserve(max(0, len));
            for (int i = 0; i < len; ++i) v.push_back(a[(start + i) % n]);
            return v;
        };

        long long ans = INF;

        // Case 1: block covering index 0 is a PAIR (0,1)
        if (n >= 2) {
            ans = min(ans, llabs(a[0] - a[1]) + dp_line(seg(2, n - 2)));
            // Case 2: block covering index 0 is a PAIR (n-1,0)
            ans = min(ans, llabs(a[n - 1] - a[0]) + dp_line(seg(1, n - 2)));
        }

        // Case 3: block covering index 0 is a TRIPLE (0,1,2)
        if (n >= 3) {
            long long mx, mn;

            mx = max(a[0], max(a[1], a[2]));
            mn = min(a[0], min(a[1], a[2]));
            ans = min(ans, (mx - mn) + dp_line(seg(3, n - 3)));

            // Case 4: TRIPLE (n-1,0,1)
            mx = max(a[n - 1], max(a[0], a[1]));
            mn = min(a[n - 1], min(a[0], a[1]));
            ans = min(ans, (mx - mn) + dp_line(seg(2, n - 3)));

            // Case 5: TRIPLE (n-2,n-1,0)
            mx = max(a[n - 2], max(a[n - 1], a[0]));
            mn = min(a[n - 2], min(a[n - 1], a[0]));
            ans = min(ans, (mx - mn) + dp_line(seg(1, n - 3)));
        }

        cout << ans << "\n";
    }
    return 0;
}