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
Date: 2025-06-04 18:39:04
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

string dic[30] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int di[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};

void solve() {
    string a, b;
    int k = 0;
    vi k1(10, 0);
    getline(cin, a);
    int idx;
    
    while (1) {
        idx = int(a.find(" "));
        if (idx == -1) {
            b = a;
            for (int i = 0; i < 26; ++i) {
                if (b == dic[i]) {
                    if (i == 0) break;
                    k1[k++] = di[i];
                }
            }
            break;
        }
        
        b = a.substr(0, idx);
        a = a.substr(idx + 1);
        for (int i = 0; i < 26; ++i) {
            if (b == dic[i]) {
                if (i == 0) break;
                k1[k++] = di[i];
            }
        }
    }
    
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    
    sort(k1.begin(), k1.begin() + k);

    bool first = true;
    for (int i = 0; i < k; ++i) {
        if (k1[i] == 0) continue;
        if (!first && k1[i] < 10) {
            cout << "0";
        }
        cout << k1[i];
        first = false;
    }
    
    if (first) {
        cout << 0;
    }
    cout << endl;
}

signed main() {
    //cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}