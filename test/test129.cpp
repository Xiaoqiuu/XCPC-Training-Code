/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-04-29 16:23:50
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-04-29 16:48:00
 * @FilePath: /workspace/test/test129.cpp
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
Date: 2026-04-29 16:24:03
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
    // int a = INT_MAX;
    // bitset<32> ba = a;
    // cout << "sizeof a : " << sizeof(a) << ", val of a : " << a << endl;
    // cout << ba << endl;
    // short b = a;
    // cout << "sizeof b : " << sizeof(b) << ", val of b : " << a << endl;
    // bitset<32> bb = static_cast<unsigned short>(b);
    // cout << bb << endl;

    short int a = SHRT_MAX;
    bitset<16> ba = a;
    cout << "sizeof a : " << sizeof(a) << ", val of a : " << a << endl;
    cout << ba << endl;
    int b = a;
    cout << "sizeof b : " << sizeof(b) << ", val of b : " << a << endl;
    bitset<32> bb = b;
    cout << bb << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
