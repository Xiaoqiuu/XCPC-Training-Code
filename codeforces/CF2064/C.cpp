#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

void solve() {
    int n; cin >> n;

    vl dp(2);
    for(int i = 0;i < n; ++ i) {
        ll t;
        cin >> t;
        if(t < 0) dp[1] -= t;
        else dp[0] += t;

        if(dp[1] < dp[0]) {
            dp[1] = dp[0];
        }
    }

    cout << dp[1] << endl;
}

signed main(){
    fast_io;
    int _ ;
    cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}