#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long int
signed main(){
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++ i) {
        int x = 0; cin >> x;
        if (x < n) {
            a[x] ++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i) {
        if (a[i] > 0)ans += i *a[i];
    }
    cout << ans << endl;
    akitama;
}