#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define akitama return 0
#define vi vector<int>
#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi pre(n, 0);
    if (n)
        pre[0] = (s[0] == 'u');
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (s[i] == 'u');
    }
    ll ans = 0;
    string pat = "uwawauwa";
    for (int j = 0; j + 7 < n; j++) {
        if (s.compare(j, 8, pat) == 0) {
            if (j >= 2)
                ans += pre[j - 2];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    akitama;
}
