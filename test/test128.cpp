/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-04 15:50:31
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-04 16:03:29
 * @FilePath: /workspace/test/test128.cpp
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
Date: 2026-05-04 15:50:33
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
    char str[] = "heo";

    char *p = (char*)memchr(str, 'l', 3);

    if (p != NULL) {
        printf("找到了，位置是：%ld\n", p - str);
    } else {
        cout << -1 << endl;
    }

    // return 0;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
