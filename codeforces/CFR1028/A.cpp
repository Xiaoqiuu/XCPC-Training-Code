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
#define akitama return 0
/*
Author: Akitama
Date: 2025-05-31 22:33:16
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < d && b <= c) {
        if (b <= a) cout << "Gellyfish" << endl;
        else cout << "Flower" << endl;
    } else if (a >= d && b <= c) {
        cout << "Gellyfish" << endl;
    } else if (a< d && b >= c + 1) {
        cout << "Flower" << endl;
    } else {
        if (d > c) {
            cout << "Flower" << endl;
        } else {
            cout << "Gellyfish" << endl;
        }
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
