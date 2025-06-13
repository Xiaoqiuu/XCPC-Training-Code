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
#include <tuple>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-06-12 22:50:16
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
#define eb emplace_back

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int>> o;
    // o.reserve((n - 1)*2);
    o.eb(1, 1, n);
    for (int i = 2; i <= n; ++ i) {
        int k = i - 1;
        int p = n - k;
        // if (k == 0) continue;
        o.eb(i, 1, p);
        // o.eb(i, 1, k);
        // o.eb(i, i, n);
        if (p <= n - 1) o.eb(i, p + 1, n);
    }
    cout << o.size() << endl;
    for (auto& i : o) {
        int x, l, r;
        tie(x, l, r) = i;
        cout << x << " " << l << " " << r << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
