#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

#define akitama return 0

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        ll m = a[0];
        bool ans = 1;
        for (int i = 1; i < n; ++ i) {
            if (a[i] > m * 2 - 1) {
                ans = 0;
                break;
            }
            m = min(m, a[i]);
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
    akitama;
}