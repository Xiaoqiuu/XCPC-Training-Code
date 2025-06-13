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
    vl vec(n+4);
    vl cnt(n+4, 0);
    for (int i = 1;i <= n; ++ i) {
        cin >> vec[i];
        cnt[vec[i]]++;
    }

    vl ans(n+4);
    ans[0] = 0;
    ll mx = 0, l = 0, r = 0;
    for(ll i = 1;i <= n; ++ i) {
        if (cnt[vec[i]] != 1) {
            ans[i] = 0;
        } else {
            ans[i] = ans[i - 1] + 1;
        }
        if (ans[i] > mx) {
            mx = ans[i];
            l = i + 1 -ans[i];
            r = i;
        }
    }
    cout << l << " ";
    if (r > 0) cout << r;
    cout << endl;
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