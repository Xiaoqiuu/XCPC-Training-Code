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
Date: 2026-05-23 20:04:28
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

int check(char c) {
    if (c == 'a' || c == 'b' || c == 'c') return 2;
    else if (c == 'd' || c == 'e' || c == 'f') return 3;
    else if (c == 'g' || c == 'h' || c == 'i') return 4;
    else if (c == 'j' || c == 'k' || c == 'l') return 5;
    else if (c =='m' || c == 'n' || c == 'o') return 6;
    else if (c == 'p' || c == 'q' || c == 'r' || c =='s') return 7;
    else if (c == 't' || c == 'u' || c == 'v') return 8;
    else if (c == 'w' || c == 'x' || c == 'y' || c == 'z') return 9;
    return 0;
}

void solve() {
    int n; cin >> n;
    string s;
    // int ans = 0;
    while (cin >> s) {
        cout << check(s[0]);
    }
    // cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
