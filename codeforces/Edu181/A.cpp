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
Date: 2025-07-22 22:37:05
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
    string s;cin >> s;
    string ans = "";
    ll f = 0, n = 0, t = 0;
    for (int i = 0; i < (int)s.size(); ++ i) {
        if (s[i] == 'F') 
            f++;
        else if (s[i] == 'N')
            n++;
        else if (s[i] == 'T')
            t++;
        else ans += s[i];
    }
    for (int i = 0; i < t; ++ i) cout << 'T';
    cout << ans;
    for (int i = 0; i < f; ++ i) cout << 'F';
    for (int i = 0; i < n; ++ i) cout << 'N';
    cout << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
