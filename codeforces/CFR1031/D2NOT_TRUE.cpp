#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
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
Date: 2025-07-21 22:03:37
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
// #define l(x) x << 1
// #define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

vi a, b;

template<typename T>
bool cmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

void solve() { 
    int n; cin >> n;
    // a.resize(n);
    // b.resize(n);
    // for (auto &i: a) cin >> i;
    // for (auto &i :b) cin >> i;
    deque<int> a, b;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        a.pb(x); 
    }
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        b.pb(x);
    }
    ll ans = 0;

    // for (int i = 0; i < n; ++ i) {
    //     if (a[i] > b[i]) ans ++;
    // }

    while (n--) {
        if(a.front() > b.front()) {
            ans++;
            a.pop_front();
        } else {
            b.pop_front();
        }
    }

    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int _; cin >> _;
    while (_--) solve();
    akitama;
}