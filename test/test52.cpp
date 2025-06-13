#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define akitama return 0


void solve() {
    string s = "ABCDEFG", t = s;
    reverse(s.begin(), s.end());
    cout << t << s << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}