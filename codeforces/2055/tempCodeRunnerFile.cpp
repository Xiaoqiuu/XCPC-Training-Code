#include <bits/stdc++.h> 
//#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define akitama return 0

void solve() {
    int num;cin >> num;
    ll a[num+1], b[num+1];
    ll dec = 0, sur = 0, min_val = INT_MAX;
    for (int i = 1; i <= num; i++) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    for (int i = 1; i <= num; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= num; ++i) {
            if (a[i] < b[i]) {
                dec += (b[i] - a[i]);
            } else {
                sur += (a[i] - b[i]);
            }
        }
        if (dec <= sur / (num - 1)) {
            if (dec >= min_val)
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--) {
        solve();
    }
    akitama;
}