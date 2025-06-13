#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define akitama return 0

bool check(const string& s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s < s1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (check(s)) {
        cout << "YES" << endl;
        return;
    }

    if (k == 0) {
        cout << "NO" << endl;
        return;
    }

    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    if (check(sorted_s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    akitama;
}