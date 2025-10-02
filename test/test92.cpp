#include <bits/stdc++.h>
using namespace std;

signed main() {
    // int n; cin >> n;
    // string s, t;
    // for (int i = 1; i <= n; ++ i) {
    //     t += to_string(i);
    //     s += t;
    // }
    // cout << s << endl;


    int n, m; cin >> n >> m;
    string s = "", t = "";
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        t += to_string(i);
        s += t;
    }
    cout << s << endl;
    string f;
    for (int i = 0; i < m; ++ i) {
        int x; cin >> x;
        f += to_string(x);
    }

    cout << f << endl;
}