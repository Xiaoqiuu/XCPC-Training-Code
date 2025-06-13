#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long
#define akitama return 0
void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == y) { printf("-1\n");return; }
    ll k = 0;
    while (true) {
        if ((x + k) + (y + k) == ((x + k)^(y + k))) break;
        ll u = 1, t = (x + k) & (y + k);
        while (t) {
            t = t >> 1;
            u = u << 1;
        }
        u = u >> 1;
        k += u - max((x+k)%u, (y+k)%u);
    }
    printf("%lld\n", k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    akitama;
}