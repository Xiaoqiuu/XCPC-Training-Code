#include <bits/stdc++.h>
using namespace std;

void f(int n) {
    bool flag = 0;
    while (n != 0) {
        int k = int(log2(n));
        if (flag) cout << "+";
        if (k == 0) {
            cout << "2(0)";
        } else if (k == 1) {
            cout << "2";
        } else {
            cout << "2(";
            f(k);
            cout << ")";
        }
        n -= pow(2, k);
        flag = 1;
    }
}

signed main() {
    int n; cin >> n;
    f(n);
}