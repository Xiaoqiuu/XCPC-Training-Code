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
Date: 2025-07-19 18:33:12
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
    ll m;
    cin >> n >> m;

    //n n(n+1)/2

    if (m < n || m > ((ll)n * (n + 1)) / 2) {
        cout << -1 << endl;
        return;
    }

    // cout << "o" << endl;
    for (int i = n; i >= 1; -- i) {
        ll t = ll(n + i) * (n - i + 1) / 2 + i - 1;
        if (t >= m) {
            ll cut = i - (t - m);
            if (i == n) {
                cout << cut << endl;
            } else {
                cout << n << endl;
                for (int j = n; j >= i + 2; -- j) {
                    cout << j << " " << j - 1 << endl;
                }
                cout << i + 1 << " " << cut << endl;
            }
            if (cut > 1) {
                cout << cut << " " << 1 << endl;
            }
            for (int j = 1, last = 1; j <= i; ++ j) {
                if (j == last || j == cut) continue;
                cout << last << " " << j << endl;
                last = j;
            }
            return;
        }
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
