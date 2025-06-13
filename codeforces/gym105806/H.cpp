#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int 
#define ull unsigned long long int

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int pos = INT_MAX, ans = 0;
    int tar = n/2;
    for (int i = 0; i < n; ++ i) {
        if (s[i] == '0' && abs(i - tar) < abs(pos - tar)) pos = i;
    }
     
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }

    akitama;
}