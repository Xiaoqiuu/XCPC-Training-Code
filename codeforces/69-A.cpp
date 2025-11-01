#include <iostream>
typedef long long int ll;

using std::cin;
using std::cout;
using std::endl;

#define akitama return 0

ll a = 0, b = 0, c = 0;

signed main() {
    int _; cin >> _;
    while (_--) {
        ll x, y, z; cin >> x >> y >> z;
        a += x, b += y, c += z;
    }
    cout << (a == 0 && b == 0 && c == 0 ? "YES" : "NO") << endl;
    akitama;
}

