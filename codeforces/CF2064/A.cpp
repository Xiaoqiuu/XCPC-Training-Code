#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s;cin >> s;
    int ans = 0;
    for(int i = 1;i < n; ++ i) {
        if (s[i - 1] != s[i]) {
            ans ++;
        }
        
    }
    if (s[0] == '1') {
        ans ++;
    }
    cout << ans << endl;
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