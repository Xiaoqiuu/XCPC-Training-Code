#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

#define akitama return 0

bool cmp(const string &s1, const string &s2) {
    return s1 < s2;
}

signed main() {
    int n; cin >> n;
    vector<string> s(n);
    for (string &i : s) {
        cin >> i;
    }
    std::cout << "-----------\n";
    sort(s.begin(), s.end(), cmp);
    for (string i : s) {
        std::cout << i << std::endl;
    }

    akitama;
}