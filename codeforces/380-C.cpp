#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define akitama return 0
using ll = long long int;
#define vi vector<int>

void init(string s, vector<int>& dp) {
    int n = s.size();
    int cntl = 0, cntr = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            cntl++;
            dp[i+1] = dp[i];
        } else {
            if (cntl > cntr) {
                cntr++;
                dp[i+1] = dp[i] + 1;
            } else {
                dp[i+1] = dp[i];
            }
        }
    }
}

void solve() {
    string s; cin >> s;
    vi dp(s.size()+1, 0);
    init(s, dp);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << 2*(dp[r] - dp[l]) << endl;
    }
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