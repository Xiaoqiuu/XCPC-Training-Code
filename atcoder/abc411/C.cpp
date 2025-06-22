#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<bool> c(n + 2);
    unordered_set<int> s;
    int ans = 0;
    while (q--) {
        int a;
        cin >> a;
        if (c[a]) {
            c[a] = 0;
            s.erase(a);
            bool l = c[a - 1], r = c[a + 1];
            if (l && r) ans++;
            else if (!l && !r) ans--;
        } else {
            c[a] = 1;
            s.insert(a);
            bool l = c[a - 1], r = c[a + 1];
            if (l && r) ans--;
            else if (!l && !r) ans++;
        }
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}