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
Date: 2025-07-05 22:41:49
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
    ll a, b, x, y; cin >> a >> b >> x >> y;
    if (a == b) {
        cout << 0 << endl;
        return;
    } else if (a < b) {
        ll cur = a;
        ll cost = 0;
        for (ll i = 0; i < b - a; ++ i) {
            if ((cur % 2 == 0)&&(y < x)) {
                cost += y;
            } else {
                cost += x;
            }
            cur++;
        }
        cout << cost << endl;
        return;
    } else {
        if ((a == b + 1) && (a % 2 == 1)) {
            cout << y << endl;
        } else cout << -1 << endl;
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
