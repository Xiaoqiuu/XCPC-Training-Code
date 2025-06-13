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
#define endl '\n'

vl a(1001);
//int ans = 0;

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
        a[i] = num;
        num *= 2;
    }
}

// void solve() {
//     //process();
//     int n; cin >> n;
//     vl num(n);
//     int sum = 0;
//     for (int i = 0; i < n; ++ i) {
//         cin >> num[i];
//         sum += num[i];
//     }
//     for (int i = 28; i >= 0; -- i) {
//         if(i == 0) { if(sum) ans |= 1; break; }
//         //if (a[i] > sum) continue;
//         //else {
//             if (sum > quick_m(2, i) * n - n) {
//                 sum -= min(sum / quick_m(2, i), n) * quick_m(2, i);
//                 ans |= 1 << i;
//             }
//         //}
//         if (!sum) break;
//     }
//     cout << ans << endl;
// }


void solve() {
    ll n; cin >> n;
    ll ans = 0;
    ll tmp, sum = 0;
    for (int i = 0; i < n; ++ i) {
        cin >> tmp;
        sum += tmp;
    }
    for (int i = 30; i >= 0; -- i) {
        if (sum > ((1 << i) - 1) * n) {
            ans |= 1 << i;
            ll temp = min(n, sum >> i);
            sum -= temp * (1 << i);
        }
    }

    cout << ans << endl;
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