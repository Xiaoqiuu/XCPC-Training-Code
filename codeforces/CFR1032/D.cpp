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
Date: 2025-07-23 02:37:53
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
    // ll ans1 = 0;
    vector<pair<int, int>> ans;
    // for (int i = n - 1; i > 0; -- i) {
    //     if (a[i] > a[i - 1]) {
    //         int tmp = a[i];
    //         a[i] = a[i - 1];
    //         a[i - 1] = tmp;
    //         ans++;
    //     }
    // }
    // for (int i = n - 1; i > 0; -- i) {
    //     if (b[i] > b[i - 1]) {
    //         int tmp = b[i];
    //         b[i] = b[i - 1];
    //         b[i - 1] = tmp;
    //         ans++;
    //     }
    // }
    
    // for (int i = )
    // 2
    // 100 33
    // 98 1

    // 1 2 3
    // 4 5 6
    auto check = [&](int k, int i) {
        ans.emplace_back(k, i + 1);
        if (k == 1) {
            swap(a[i], a[i + 1]);
        } else if (k == 2) {
            swap(b[i], b[i + 1]);
        } else {
            swap(a[i], b[i]);
        }
    };
    for (int i = 0; i < n; ++ i) {
        for (int j = i - 1; j >= 0; -- j) {
            if (a[j] > a[j + 1])
                check(1, j);
            if (b[j] > b[j + 1])
                check(2, j);
            // else check(3, j);
        }        
    }
    for (int i = 0; i < n; ++ i) {
        if (a[i] > b[i]) check(3, i);
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << " " << y << endl;
    }
    ans.shrink_to_fit();
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
