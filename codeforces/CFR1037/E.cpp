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
Date: 2025-07-19 17:41:47
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

vll p, s;

void solve() {
    int n; cin >> n;
    p.resize(n);
    s.resize(n);

    for (int i = 0; i < n; ++ i) { cin >> p[i]; }
    for (int i = 0; i < n; ++ i) { cin >> s[i]; }
    // P_i-1 P_i
    // S_i S_i+1
    if (p[n-1]!=s[0]) {
        cout << "No" << endl;
        return;
    }
    vll res = p;
    for (int i = n - 1; i >= 0; -- i) {
        ll tar = std::lcm(res[i], s[i]);
        res[i] = tar;
    }
    int A = res[0];
    for (int i = 0; i < n; ++ i) {
        A = gcd(A, res[i]);
        if (A != p[i]) {
            cout << "No" << endl;
            return;
        }
    }
    A = s[n - 1];
    for (int i = n - 1; i >= 0; -- i) {
        A = gcd(A, res[i]);
        if (A != s[i]) {
            cout << "No\n";
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
