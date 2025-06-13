//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define ll long long
#define akitama return 0
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define fast_io cin.tie(nullptr)->ios::sync_with_stdio(false)
#define endl '\n'

const int MOD = 998244353;
/*
    AKITAMA CODEFORCES EDU174 C SOLUTION 25.2.18 
    TARGET: up to C++23 
*/

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    ll f1 = 0, f2 = 0, ans = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 1) {
            f1 = (f1 + 1) % MOD;
        } else if (a[i] == 2) {
            f2 = (f2 * 2 + f1) % MOD;
        } else if (a[i] == 3) {
            ans = (ans + f2) % MOD;
        }
    }
    cout << ans << endl;
}

signed main() {
    fast_io;
    int _;
    cin >> _;
    while (_) {
        solve();_--;
    }
    akitama;
}
