#include <string>
#include <iostream>

using namespace std;

#define ll long long int
#define akitama return 0

void solve();

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }

    akitama;
}

void solve() {
    int t; cin >> t;
    string s = to_string(t);
    int n = s.length();
    cout << "The length of string is: " << n << endl;
    cout << "The string is: " << s << endl;
}