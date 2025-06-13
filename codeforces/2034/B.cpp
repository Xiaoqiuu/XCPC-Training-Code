#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define akitama return 0

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '1') cnt = 0;
        else cnt ++;
        if (cnt == m) {
            cnt = 0;
            ans ++;
            i += k - 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) solve();
    akitama;
}