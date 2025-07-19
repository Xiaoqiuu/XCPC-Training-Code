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
Date: 2025-07-19 20:18:53
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
    int n;
    string s;
    cin >> n >> s;
    int m = 1 << n;
    vector<char> o(m, 0);
    o[0] = 1;
    for (int i = 1; i < m ; ++ i) {
        o[i] = (s[i - 1] == '0');
    }

    if (!o[m - 1]) {
        cout << "No\n";
        return;
    }
    bool ok = 1;
    for (int i = 1; i < m && ok; ++ i) {
        if (o[i]) continue;
        bool f = 0;
        for (int b = 0; b < n; ++ b) {
            if (i & (1 << b)) {
                int pre = i ^ (1 << b);
                if (o[pre]) {
                    f = 1;
                    break;
                }
            }
        }
        if (!f) ok = 0;
    }
    cout << (ok? "Yes\n" : "No\n");
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
