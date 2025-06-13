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

using namespace std;

#define akitama return 0
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'

// vl a(21);

// inline void process() {
//     int num = 1;
//     for (int i = 0; i <= 20; ++ i) {
//         a[i] = num;
//         num *= 2;
//     }
// }

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "Fluttershy" << endl; return;
    } else if (n == 2 | n == 3) {
        cout << "Pinkie Pie" << endl; return; }
        else {
            if((n - 3)% 4 == 1 || (n - 3) % 4 == 2) {
                cout << "Fluttershy" << endl;
            } else {
                cout << "Pinkie Pie" << endl;
            }
        }
}



signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}