#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <utility>
#include <iomanip>
#include <bitset>

using namespace std;

#define akitama return 0
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vl vector<ll>
//#define endl '\n'

int k, n;
ll ans = 0;

inline int quick_m(int a, int b) {
    int l = 1;
    while (b) {
        if (b % 2) l *= a;
        a *= a;
        b /= 2;
    }
    return l;
}

inline void process() {
    int num = 1;
    for (int i = 0; i <= 1000; ++ i) {
        //a[i] = num;
        num *= 2;
    }
}
bool query(int i, int j, int k);
bool check(int x) { int cnt = 0; 
    for (int i = 1, j = n; i <= n; ++ i) {
        while (j >= 1 && !query(i, j, x)) j --;
        cnt += n - j;
    }
    return cnt >= k;
}

bool query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    int num;
    cin >> num;
    return num;
}


void solve() {
    cin >> n >> k;
    ll l = 1, r = n * n;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << "! " << ans << endl;
}


signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    //cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}