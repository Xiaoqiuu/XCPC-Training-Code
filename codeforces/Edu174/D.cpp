#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

/*
    AKITAMA CODEFORCES EDU174 D SOLUTION 25.2.18
    After Competition Time
    TARGET: up to C++23
*/

int check(string& s) {
    int len = s.size();
    vi cnt(26, 0), _cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    int ans = len;
    for (int i = len - 1; i >= 0; -- i) {
        cnt[s[i] - 'a']--;
        _cnt[s[i] - 'a']++;
        if (i < len >> 1) {
            if (s[i] == s[len-i-1]) {
                _cnt[s[i] - 'a'] -= 2;
            } else {
                ans = min(ans, i+1);
                break;
            }
        }
        if (cnt[s[i] - 'a'] < _cnt[s[i] - 'a']) {
            ans = min(ans, i + 1);
            break;
        }
    }
    return ans;
}

void solve() {
    
    string s;
    cin >> s;
    int len = s.size();
    int l = 0, r = len - 1;
    while (l < r && s[l] == s[r]) {
        l++, r--;
    }
    if (l >= r) {
        cout << 0 << endl;
        return;
    }

    s = s.substr(l, r-l+1);
    //len = s.size();
    int ans = check(s);
    reverse(s.begin(), s.end());
    ans = min(ans, check(s));
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
