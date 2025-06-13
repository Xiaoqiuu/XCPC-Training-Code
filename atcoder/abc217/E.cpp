#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
// #include <multiset>

using namespace std;
using ll = long long int;
using ld = long double;
#define akitama return 0
#define vi vector<int>
#define vll vector<ll>

const int N = 1e6 + 7;
vi a(N, 0);

void solve() {
    ll q; cin >> q;
    multiset<int> mse;
    int i = 1, op, x, flag = 0;
    bool st[N];
    while (q--) {
        cin >> op;  
        switch(op) {
            case 1: 
                cin >> x;
                a[++flag] = x;
                break;
            case 2:
                if (mse.size()) {
                    cout << *mse.begin() << endl;
                    mse.erase(mse.begin());
                } else {
                    cout << a[i] << endl;
                    st[i] = true;
                    i ++;
                }
                break;
            default:
                for (int j = i; j <= flag; j ++) {
                    if (!st[j]) {
                        mse.insert(a[j]);
                    }
                    i = flag + 1;
                }
        }
    }
    return;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}