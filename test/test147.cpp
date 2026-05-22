/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-30 19:16:32
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-30 19:39:38
 * @FilePath: /workspace/test/test147.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
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
Date: 2026-04-30 19:16:38
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
    // int k = 2;
    // int a = -872322323;
    // bitset<32> b(a);
    // cout << b << endl;
    // int c = (a << k);
    // bitset<32> d(c);
    // cout << d << endl;
    // cout << "val of c: " << c << endl;
    int k = 2;
    int a = INT_MAX;
    bitset<32> b(a);
    cout << b << endl;
    int c = (a >> k);
    bitset<32> d(c);
    cout << d << endl;
    cout << "val of c: " << c << endl;
}


signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
