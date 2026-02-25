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
Date: 2026-02-12 23:26:54
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
#define int ll
constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

void solve() {
    // 2 6 6 7 7 7
    // 6 7 7 7 2 6
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    auto sa = a;
    sort(sa.begin(), sa.end());
    if (a == sa) {
        cout << -1 << endl;
        return;
    }
    int k = sa[n - 1] - sa[0];
    for (int i = 0; i < n; ++ i) {
        if (a[i] != sa[i]) {
            k = min(k, max(sa[i] - sa[0], sa[n - 1] - sa[i]));
        }
    }
    // int k = 0;
    // for (int i = 0; i < n - 1; ++ i) {
    //     for (int j = i + 1; j < n; ++ j) {
    //         if (a[i] > a[j]) {
    //             k = max(abs(a[i] - a[j]), k);
    //             int tmp = a[i];
    //             a[i] = a[i - 1];
    //             a[i - 1] = tmp;
    //         }
    //     }
    // }
    
    cout << k << endl;
    // vi sa = a;
    // sort(sa.begin(), sa.end(), [](int& a, int& b){
    //     return a <= b;
    // });
    // int k = 0;
    // for (int i = 0; i < n; ++ i)  {
    //     k = max(k, abs(sa[i] - a[i]));
    // }
    // cout << (k? k : -1) << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
