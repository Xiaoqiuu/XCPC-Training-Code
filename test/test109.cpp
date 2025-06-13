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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-22
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
vi a(N);
void solve() {
    int n; cin >> n;
    int i = 0;
    a[i++] = n;
    while (n != 1) {
        if (n % 2 == 0) {
            n >>= 1;
            a[i++] = n;
        } else {
            n *= 3;
            n ++;
            a[i++] = n;
        }
    }
    i--;
    for (; i >= 0; -- i) {
        cout << a[i] << " ";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
