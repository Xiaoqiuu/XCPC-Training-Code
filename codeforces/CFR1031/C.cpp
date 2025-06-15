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
Date: 2025-06-15 17:42:50
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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> grid;

ll llmax(ll a, ll b) { return (a > b? a : b); }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    grid.resize(n);
    for (auto &i : grid) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0;j < m; ++ j) {
            if (grid[i][j] != '.') {
                continue;
            }
            int cnt = 0;
            int x1 = i - k;
            int x2 = i + k;
            int y1 = j - k;
            int y2 = j + k;
            bool f = 0;
            // for (int x = x1 + 1; x <= x2 - 1 && !f; ++ x) {
            //     for (int y = y1 + 1; y <= y2 - 1; ++ y) {
            //         if (x >= 0 && x > n )
            //     }
            }
            for (int y = y1; y <= y2; ++ y) {
                if (x1 >= 0 && y >= 0 && x1 < n && y < m && grid[x1][y]=='g') cnt++;
                if (x2 >= 0 && y >= 0 && x2 < n && y < m && grid[x2][y]=='g') cnt++;
            }
            for (int x = x1; x < x2; ++ x) {
                if (x >= 0 && x < n && y1 >= 0 && y1 < m && grid[x][y1]=='g') cnt++;
                if (x >= 0 && x < n && y2 >= 0 && y2 < m && grid[x][y2]=='g') cnt++;
            }
            ans = llmax(ans, cnt);
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
