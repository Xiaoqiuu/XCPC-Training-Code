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
Date: 2026-04-09 17:20:23
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
    int n, m;
    cin >> n >> m;
    vector<int> z, f;
    for (int i = 1; i <= n; ++ i) {
    //    cin >> a[i];
        int x; cin >> x;
        if (x < 0) {
            f.pb(x);
        } else {
            z.pb(x);
        }
    }
    sort(z.begin(), z.end());
    sort(f.begin(), f.end(), [](int x, int y){
        return x > y;
    });

    // for (auto i : f) cout << i << " ";
    vi a(f.size(), 0), b(z.size(), 0);
    if (!a.empty()) a[0] = abs(f[0]);
    if (!b.empty()) b[0] = z[0];
    for (int i = 1; i < f.size(); ++ i) {
        a[i] = a[i - 1] + abs(f[i]);
    }
    for (int i = 1; i < z.size(); ++ i) {
        b[i] = b[i - 1] + z[i];
    }

    int pos = 0;
    int cnt = 0;
    int ai = 0, bi = 0;
    bool side = 1; // left = 0 right = 1
    while (pos <= m) {
        if (cnt == 0) {
        if (a[ai] > b[bi]) {
            pos += b[bi];
            bi++;
            cnt++;
            side = 0;
        } else {
            pos += a[ai];
            ai++;
            cnt++;
        }}
        else {
            if (!side) {
                if (ai >= f.size() || a[ai+1] +a[ai] > a[ai] + b[bi]) {
                    side = 1;
                    pos += a[(ai < f.size()? ai:--ai)]+b[bi];
                    bi++;
                    cnt++;
                } else {
                    if ()
                }
            }
        }
    }
    
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
