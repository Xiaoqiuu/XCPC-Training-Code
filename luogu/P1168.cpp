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
Date: 2025-08-01 12:02:36
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
    int n; cin >> n;
    priority_queue<int, vi, less<int>> big_q;
    priority_queue<int, vi, greater<int>> small_q;
    vi a(n + 1);
    cin >> a[1];
    int mid = a[1];
    cout << mid << endl;
    for(int i = 2;i <= n; ++ i) {
        cin >> a[i];
        if (a[i] < mid) big_q.push(a[i]);
        else small_q.push(a[i]);
        if (i & 1) {
            while(big_q.size()!=small_q.size()){
                if(big_q.size()>small_q.size()){
                    small_q.push(mid);
                    mid=big_q.top();
                    big_q.pop();
                }
                else{
                    big_q.push(mid);
                    mid=small_q.top();
                    small_q.pop();
                }
            }
            cout<<mid<<endl;
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
