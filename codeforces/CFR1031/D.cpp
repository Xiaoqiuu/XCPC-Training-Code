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
#include <deque>
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
Date: 2025-06-15 18:21:53
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

vi a, b;

void solve() {
    int n; cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    // 2n n
    deque<int> dq(b.begin(), b.end());
    int i = 0;
    vector<vi> lst(n);
    int score = 0;

    while (!dq.empty() && i < n) {
        if (a[i] > dq.front()) {
            score++;
            lst[i].pb(dq.front());
            dq.pop_front();
            i++;
        } else {
            lst[i].pb(dq.front());
            dq.pop_front();
        }
    }
    // vector<vi> pos(n);
    for (int h = 0; h < n; ++ h) {
        sort(lst[h].begin(), lst[h].end());
    }
    int cnt = 0;
    for (int u = 0; u < n; ++ u) {
        for (int v = u + 1; v < n; ++ v) {
            int pu = a[u], pv = a[v];
            int d = 0;
            d -= upper_bound(lst[u].begin(), lst[u].end(), pu - 1) - lst[u].begin();
            d += upper_bound(lst[v].begin(), lst[v].end(), pu - 1) - lst[v].begin();
            d -= upper_bound(lst[v].begin(), lst[v].end(), pv - 1) - lst[v].begin();
            d += upper_bound(lst[u].begin(), lst[u].end(), pv - 1) - lst[u].begin();
            cnt = max(cnt, d);
        }
    }
    cout << score + cnt << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
