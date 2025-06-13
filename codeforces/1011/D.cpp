#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pii> plates;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        plates.pb({-d, i + 1});
    }
    sort(plates.begin(), plates.end());
    int m = (n + k) / (k + 1); // 调整计算方式
    ll sum = 0;
    int cnt = 0;
    int last_pos = n + 1;
    for (auto &p : plates) {
        int pos = p.se;
        if (pos <= last_pos - (k + 1)) { // 确保时间间隔足够
            sum += -p.fi;
            cnt++;
            last_pos = pos;
            if (cnt == m) break;
        }
    }
    cout << sum << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) solve();
    return 0;
}