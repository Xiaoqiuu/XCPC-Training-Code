#include <iostream>
#define akitama return 0;
using namespace std;
using ll = long long;
using ld = long double;
int main() {
    int t;cin >> t;
    while(t--) {
        ll r, c;cin >> r >> c;
        ll l_r, l_c;cin >> l_r >> l_c;
        ll ans = 0;
                ans += c - l_c;
                ans += (r - l_r) * (2 * (c - 1) + 1);
 
        cout << ans << endl;
    }
    akitama;
}