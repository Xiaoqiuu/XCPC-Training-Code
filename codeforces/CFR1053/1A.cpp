#include <iostream>
// #include <vector>
// #include <algorithm>
#include <cstring>
#include <climits>
// #include <utility>
#include <cmath>
// #include <stack>
// #include <queue>
// #include <iomanip>
// #include <numeric>
// #include <bitset>
#include <cstdlib>
#include <set>
// #include <map>
// #include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-10-08 17:56:30
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

int n, m;
string S;

void solve() {
    cin >> n >> m >> S;
    set<int> s;

    for (int i = 1; i <= m; ++ i) {
        int x; cin >> x;
        s.insert(x);
    }

    int x = 1;
    for (int i = 0; i < n; ++ i) {
        
        if (S[i] == 'B') {
            ++x;
            while (s.find(x) != s.end()) {
                x++;
            }
            s.insert(x);
            while (s.find(x) != s.end()) {
                x++;
            } 
        } else {
            x++;
            s.insert(x);
        }
    }
    cout << s.size() << endl;
    for (auto i : s) {
        cout << i << " ";
    } cout << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
