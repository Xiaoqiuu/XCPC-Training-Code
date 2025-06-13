#include <iostream>
#include <string>

using namespace std;

#define ll long long
#define int long long

ll n, k;
string s;

int count_nanjing(const string &t) {
    int cnt = 0;
    for (int i = 0; i <= (int)t.size() - 7; ++i) {
        if (t.substr(i, 7) == "nanjing") cnt++;
    }
    return cnt;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    if (n < 7) { cout << 0 << endl; return; }

    ll ans = count_nanjing(s);

    
    string t = s;
    for (int d = 1; d <= min(k, n-1); ++d) {
        t = t.substr(1) + t[0];  
        ans = max(ans, count_nanjing(t));  
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
