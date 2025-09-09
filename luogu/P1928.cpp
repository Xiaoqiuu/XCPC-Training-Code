#include <bits/stdc++.h>
using namespace std;

string f() {
    char ch;
    int d;
    string s, str;
    while (cin >> ch) {
        if (ch == '[') {
            cin >> d;
            str = f();
            for (int i = 1; i <= d; ++ i) {
                s += str;
            }
        } else if (ch == ']') {
            return s;
        } else {
            s += ch;
        }
    }
    return s;
}

signed main() {
    // int n; cin >> n;
    cout << f();
}