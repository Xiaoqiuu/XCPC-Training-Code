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

    /  /::\       |  |:|       /  /\         /  /\      /  /::\       |  |::\       /  /::\   
   /  /:/\:\      |  |:|      /  /:/        /  /:/     /  /:/\:\      |  |:|:\     /  /:/\:\  
  /  /:/~/::\   __|  |:|     /__/::\       /  /:/     /  /:/~/::\   __|__|:|\:\   /  /:/~/::\ 
 /__/:/ /:/\:\ /__/\_|:|____ \__\/\:\__   /  /::\    /__/:/ /:/\:\ /__/::::| \:\ /__/:/ /:/\:\
 \  \:\/:/__\/ \  \:\/:::::/    \  \:\/\ /__/:/\:\   \  \:\/:/__\/ \  \:\~~\__\/ \  \:\/:/__\/
  \  \::/       \  \::/~~~~      \__\::/ \__\/  \:\   \  \::/       \  \:\        \  \::/     
   \  \:\        \  \:\          /__/:/       \  \:\   \  \:\        \  \:\        \  \:\     
    \  \:\        \  \:\         \__\/         \__\/    \  \:\        \  \:\        \  \:\    
     \__\/         \__\/                                 \__\/         \__\/         \__\/    
*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-06-01 21:31:21
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

vector<vi> a(26, vi(26, 0));

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n - 1; ++ i) {
        a[s[i]-'A'][s[i + 1] - 'A']++;
    }
    int mx = 0, x = 0, y = 0;
    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < 26; ++ j) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                x = i, y = j;
            }
        }
    }
    printf("%c%c\n", x+'A', y+'A');
}

signed main() {
    // cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
