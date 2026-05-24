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
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2026-05-23 23:00:49
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    int n; cin >> n;
    vll a(n);
    for (ll& ii : a) cin >> ii;
    vll pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; ++ i) {
        pre[i + 1] = pre[i] + llabs(a[i]);
    }
    for (int i = n - 1; i >= 0; -- i) {
        suf[i] = suf[i + 1] + a[i];
    }

    ll sum = 0;
    for (ll ii : a) sum += ii;

    ll best = sum;
    int pos = -1;

    for (int i = 0; i < n; ++ i) {
        if (a[i] > 0) {
            ll num = pre[i] - llabs(a[i]) + suf[i + 1];
            if (num > best) {
                pos = i;
                best = num;
            }
        }
    }

    if (pos == -1) {
        cout << "0\n\n";
        return;
    }

    vi c, ans;
    vi p(pos + 2, 0);
    for (int i = 0; i < pos; ++ i) {
        if (a[i] >= 0) {
            p[i] = 0;
        }
        else {
            p[i] = 1;
        }
    }
    p[pos] = 1, p[pos + 1] = 0;
    for (int i = 0; i <= pos; ++ i) {
        if (p[i + 1] ^ p[i]) {
            c.pb(i);
        }
    }

    vi pp;
    for (auto ii : c) {
        if (ii < pos) pp.pb(ii);
    }
    if (pos >= 1 && a[0] > 0) {
        if (!pp.empty()) {
            ans.pb(pp[0]);
            for (int i = 1; i < (int)pp.size() - 1; i += 2) {
                ans.pb(pp[i + 1]);
                ans.pb(pp[i]);
            }
        }
    } else {
        for (int i = 0; i < (int)pp.size() - 1; i += 2) {
            ans.pb(pp[i + 1]);
            ans.pb(pp[i]);
        }
    }
    ans.pb(pos);

    cout << ans.size() << '\n';
    for (auto ii : ans) cout << ii + 1 << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}