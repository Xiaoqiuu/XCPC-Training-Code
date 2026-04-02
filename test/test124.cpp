#include <iostream>
#define ll long long int
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a; cin >> a;
    ll ans = 1;
    for (int i = 0; i < a; ++ i) {
        ans = ans * 2;
    }
    cout << ans << endl;
}