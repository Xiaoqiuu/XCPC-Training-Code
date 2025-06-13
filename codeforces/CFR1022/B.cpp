#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <utility>
#include <climits>
#include <bitset>

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
//#define ll long long
//#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-(x))

const int MOD = 998244353;
const int N = 100005;

void solve() {
    ll n, x;
    cin >> n >> x;
    if (x == 0) {
        if (n == 1) {
            cout << -1 << endl;
        } else if (n % 2 == 0) {
            cout << n << endl;
        } else {
            cout << n + 3 << endl;
        }
    } else {
        if (n == 1) {
            cout << x << endl;
            return;
        }
        ll s = (n - 1) % 2;
        ll last = x ^ s;
        ll sum1 = (last > 0)? (n + last - 1) : -1, sum2 = 0;
        ll s_n = (n - 2) % 2;
        ll k = x ^ s_n;
        if (k == 0) {
            sum2 = (n - 2) + 2;
        } else {
            sum2 = (n - 2) + k + 1;
        }
        ll res = -1;
        if (sum1 != -1) {
            res = sum1;
            if (sum2 < res) {
                res = sum2;
            }
        } else {
            res = sum2;
        }
        cout << res << endl;
    }
    return;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;cin >> _;
    //int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}