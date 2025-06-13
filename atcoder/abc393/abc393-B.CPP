#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define fast_io ios::sync_with_stdio(false),cin.tie(nullptr)
#define endl '\n'

void solve() {
    int ans = 0;
    string s; cin >> s;
    for(int i = 0;i < s.size();++ i) {
        for(int j = i + 1;j < s.size();++ j) {
            int k = j + (j - i);
            if(k >= s.size()) continue;
            if(s[i] == 'A' && s[j] == 'B' && s[k] == 'C') ans ++;
        }
    }

    cout << ans << endl;
}

signed main(){
    fast_io;
    int _ =1;
    // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}