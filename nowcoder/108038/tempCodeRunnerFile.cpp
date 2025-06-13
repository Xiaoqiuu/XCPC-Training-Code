#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
using ll = long long int;

signed main() {
    int n; cin >> n;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; ++ i) {
        if (i == 1) cin >> a[i];
        else if (i <= 10) {
            cin >> a[i];
            a[i] += a[i-1];
        }
        else {
            cin  >> a[i];
            a[i] += a[i-1] - a[i-9];   
        }
    }
    sort(a.begin(), a.end());
    cout << a[n] << endl;
    akitama;
}