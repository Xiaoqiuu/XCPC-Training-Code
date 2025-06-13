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
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-27 00:15:40
Description: Contest Template
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 操作次数至少要>=n
    if(k < n) {
        cout << "NO\n";
        return;
    }
    int need = k - n;
    ll max_spl = 0;
    for(ll v : a) {
        // __builtin_ctzll 计算 v 的二进制末尾有多少个 0
        max_spl += __builtin_ctzll(v);
        // 如果中途已经够了，就可以提前退出
        if(max_spl >= need) break;
    }
    cout << (max_spl >= need ? "YES\n" : "NO\n");
}


signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
