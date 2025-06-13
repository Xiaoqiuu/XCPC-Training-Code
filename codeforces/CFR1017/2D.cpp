#include <iostream>
#include <string>
using namespace std;

#define akitama return 0
#define ll long long int

void solve() {
    string p, s;
    cin >> p >> s;
    int ip = 0, is = 0;
    int j = 0;
    for (int i = 0; i < p.size();) {
        ip = i + 1;
        while (ip < p.size() && p[i] == p[ip]) ip++;
        is = j + 1;
        while (is < s.size() && s[j] == s[is]) is++;
        if (j >= s.size() || p[i] != s[j] || is - j > (ip - i) * 2 || is - j < ip - i) {
            cout << "NO\n";
            return;
        }
        i = ip;
        j = is;
    }
    if (j != s.size()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) { solve(); _--; }
    akitama;
}