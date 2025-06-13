#include <iostream>
using namespace std;

#define ll long long int
#define akitama return 0

void solve(){
    int t ; cin >> t;
    ll ans= 0;
    while (t--) {
        unsigned long long int n; cin >> n;
        if(n & (n - 1) != 0) ans++;
    }

    cout << ans << endl;
    
    // ll ans = 0;
    // int t; cin >> t;
    // while(t--) {
    //     unsigned long long int n; cin >> n;
    
    // if (n % 9 == 0 || n % 7 == 0 || n % 5 == 0 || n % 3 == 0) ans++;
    // else {
    //     if(n%8==4|| n %6 == 3 || n%4==2) ans++;
    // }
    // }
    // cout<<ans<<endl;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_--){
        solve();
    }
    akitama;
}