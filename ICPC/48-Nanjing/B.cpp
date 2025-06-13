#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define akitama return 0
#define int long long

void solve() {
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int cnt[2][2]{};
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '2') cnt2 ++;
        else cnt[i&1][s[i]-'0'] ++;
    }

    cnt0 = abs(cnt[0][0] - cnt[1][0]);
    cnt1 = abs(cnt[0][1] - cnt[1][1]);
    
    int tmp = min(cnt0, cnt2);
    cnt2 -=tmp, cnt0 -= tmp;
    tmp = min(cnt1, cnt2);
    cnt1 -= tmp, cnt2 -= tmp;
    cnt2 %= 2;

    cout << cnt0 + cnt1 + cnt2 << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }

    akitama;
}