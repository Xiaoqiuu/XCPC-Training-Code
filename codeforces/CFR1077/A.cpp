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
Date: 2026-02-12 21:51:07
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

// 4 5 3 6 2 7 1

// 4 5 3 6 2 7 1 8

void solve() {
    int n; cin >> n;
    cout << ((n + 1) / 2) << " ";
    for (int i = 1; i <= (n&1? (n)/2 : n/2); ++ i) {
        
        if (((n + 1) / 2)  + i <= n) cout << ((n + 1) / 2) + i << " ";
        if (((n + 1) / 2)  - i != 0) cout << ((n + 1) / 2)  - i << " ";
    } cout << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
