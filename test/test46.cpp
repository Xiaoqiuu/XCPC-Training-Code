#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define vl vector<ll>

#define akitama return 0

const int N = 1e5 + 5;

vl pri;
bool flag[N];

void pre(int n) {
    for (int i = 2; i <= n; ++ i) {
        if (!flag[i]) {
            pri.push_back(i);
        }
    }
}

void solve() {
    
}


signed main() {
    std::cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}