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
Date: 2025-06-12 23:36:58
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
    int n; cin >> n;
    if (n == 3) {
        cout << 4 << endl;
        cout << "2 1 3\n2 2 3\n3 1 2\n3 2 3\n";
        return;
    } else if (n >= 4) {
        cout << n + 1 << endl;
        cout << "2 1 " << n << endl;
        cout << "3 1 " << n - 1 << endl;
        cout << "3 2 " << n << endl;
        for (int i = 4; i < n; ++ i) {
            cout  << i << " 2 " << n - 1 << endl;
        }
        cout << n << " " << n - 1 << " "<<n << endl;
        cout << n << " 1 2" << endl;
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
