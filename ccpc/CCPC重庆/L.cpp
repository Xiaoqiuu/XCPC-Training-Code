#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0
constexpr int N = 1e6 + 7;
constexpr int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<ll> sum(N, 0);
    // vector<ll> st;
    // ll last_number = 0, repeat = 0;
    ll idx = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++ i) {
        // sum[i] = sum[i-1];
        string s; cin >> s;
        if (s == "Push") {
            ll num; cin >> num;
            // last_number = num;
            // repeat += num;
            sum[idx] = num;
            ans = (ans + num) % MOD;
            idx ++;
            //cout << sum[i] << endl;
        } else if (s == "Pop") {
            // sum[i] -= last_number;
            idx--;
            // repeat -= last_number;
            //cout << sum[i] << endl;
            ans = (ans - sum[idx] + MOD) % MOD;
            // cout << "sum now: " << sum[idx] << endl;
        } else if (s == "Repeat") {
            if (idx <= n) {
                ll x = idx;
                for (int k = 0; k < x; ++ k) {
                    sum[idx] = sum[k];
                    idx++;
                }
            }
            ans = ans * 2 % MOD;
        }
        cout << ans << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}