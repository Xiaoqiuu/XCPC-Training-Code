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
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-06-01 20:57:09
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

void solve() {
    int n, k; cin >> n >> k;
    // vll a(n);
    ll a[n+1];
    // for (auto &i : a) cin >> i;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a+1, a+n+1);
    // 1 3 3 5 8
    // if (a[k - 1] == a[k] || (n == 1 && a[0] == 1) || (n != 1 && k == 0)) cout << -1 << endl;
    // else if (n == 1 && k == 0 && a[0] > 1) cout << a[0] - 1 << endl;
    // else {
    //     cout << a[k-1] << endl;
    // }
    auto check = [&](int x) {
        int p = upper_bound(a+1, a+n+1, x) - a;
        p--;
        return p;
    };
    ll l = 1, r = a[n];
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid) >= k) r = mid - 1;
        else l = mid + 1;
    }
    if (check(l) != k) cout << "-1\n";
    else cout << l << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
