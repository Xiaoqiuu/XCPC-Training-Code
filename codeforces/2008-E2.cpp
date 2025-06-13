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
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) { cout << "1\n"; return; }
    if (n == 2) { 
        // if (s[0] == s[1]) cout << "1\n"; 
        // else cout << "0\n"; 
        cout << "0\n";
        return; 
    }

    vector<vi> pre1(n+1, vi(27, 0)), pre2(n+1, vi(27, 0));

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= 26; ++ j) {
            pre1[i][j] = pre1[i-1][j];
        }
        if (i % 2) pre1[i][s[i-1]-'a'+1]++;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 26; ++j) {
            pre2[i][j] = pre2[i-1][j];
        }
        if (i % 2 == 0) pre2[i][s[i-1]-'a'+1]++;
    }

    if (n % 2 == 0) {
        int max1 = 0, max2 = 0;
        for (int j = 1; j <= 26; ++j) {
            max1 = max(max1, pre1[n][j]);
            max2 = max(max2, pre2[n][j]);
        }
        cout << n - max1 - max2 << "\n";
    } else {
        int res = n;
        for (int i = 1; i <= n; ++i) {
            int max1 = 0, max2 = 0;
            for (int j = 1; j <= 26; ++j) {
                max1 = max(max1, pre1[i-1][j] + pre2[n][j] - pre2[i][j]);
                max2 = max(max2, pre2[i-1][j] + pre1[n][j] - pre1[i][j]);
            }
            res = min(res, n - max1 - max2);
        }
        cout << res << "\n";
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