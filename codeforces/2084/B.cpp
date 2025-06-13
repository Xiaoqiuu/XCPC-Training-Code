// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 998244353;
const int N = 100005;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


void solve() {
    int n; cin >> n;
    ll x = 0;
    vl a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    } sort(a.begin(), a.end());
    for (int i = 1; i < n; ++ i) {
        if (a[i] % a[0] == 0)
        x = gcd(x, a[i]);
    }
    x != a[0]? cout << "NO" <<endl : cout << "YES" << endl;
    return;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}