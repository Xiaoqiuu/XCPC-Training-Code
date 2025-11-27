#include <bits/stdc++.h>
using namespace std;
#define akitama return 0
signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++ i) {
            sum[i + 1] = s[i] + (s[i] == 'a'? -1: 1);
        }
        if (sum[n] == 0) { cout << 0 << endl; continue; }
        
        int ans = n;
        map<int, int> mp;
        mp[0] = 0;

        for (int i = 1; i <= n; ++ i) {
            if (mp.count(sum[i] - sum[n])) {
                ans = min(ans, i - mp[sum[i] - sum[n]]);
            }
            mp[sum[i]] = i;
        }
        if (ans == n) { cout << -1 << endl; continue; }
        cout << ans << endl;
    }
}