#include <iostream>
#include <set>
using namespace std;

#define int long long

signed main() {
    set<int> s;
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op & 1) {
            int n; cin >> n;
            if (!s.insert(n).second) cout << "Already Exist" << endl;
        } else {
            int n; cin >> n;
            if (s.empty()) {
                cout << "Empty" << endl;
            } else {
                auto lo = s.lower_bound(n);
                if (lo != s.end() && *lo == n) {
                    cout << n << endl;
                    s.erase(lo);
                } else if (lo == s.begin()) {
                    cout << *lo << endl;
                    s.erase(lo);
                } else if (lo == s.end()) {
                    --lo;
                    cout << *lo << endl;
                    s.erase(lo);
                } else {
                    auto pre = prev(lo);
                    if (*lo - n < n - *pre) {
                        cout << *lo << endl;
                        s.erase(lo);
                    } else {
                        cout << *pre << endl;
                        s.erase(pre);
                    }
                }
            }
        }
    }
}
