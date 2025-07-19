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
Date: 2025-07-19 16:37:38
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

vll a;

void solve() {
    int n, k; cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++ i)  {
        cin >> a[i];
    }
    int start = a[k - 1];
    // sort(a.begin(), a.end());
    std::ranges::sort(a);
    int idx = 0;
    while (start != a[idx]) idx++;
    // 2 3 5 7 9
    int t = 0;
    for (int i = idx; i < n - 1; ++ i) {
        t += a[i+1] - a[i];
        if (t > a[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
