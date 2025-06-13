#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-26 15:38:45
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

// vll a;

void solve() {
    int n; cin >> n;
    ll j = 0, o = 0;
    for (int i = 0; i < n; ++ i) {
        ll x; cin >> x;
        if (x % 2) j ++;
        else o ++;
    }
    if (!o) { cout << j - 1 << endl; return; }
    else if (!j) { cout << 1 << endl; }
    else { cout << j + 1 << endl; return; }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
