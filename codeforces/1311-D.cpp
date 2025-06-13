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
Date: 2025-06-01 20:13:53
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

const int INF = 0x3f3f3f3f;
int a1, b1, c1;
void solve() {
    // cout << "!" << endl;
    // int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int ans = INF;
    for (int i = 1; i <= a * 2; ++ i) {
        for (int j = i; j <= b * 2; j += i) {
            for (int k = 0; k < 2; ++ k) {
                int x = k * j + (c / j) * j;
                int tmp = abs(i - a) + abs(j - b) + abs(c - x);
                if (tmp < ans) {
                    ans = tmp;
                    a1 = i, b1 = j, c1 = x;
                }
            }  
        }
    }
    cout << ans << endl;
    cout << a1 << " " << b1 << " " << c1 << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
