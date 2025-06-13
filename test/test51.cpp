#include <iostream>
#include <vector>
using namespace std;

#define akitama return 0
#define vi vector<int>
#define ll long long int
#define ull unsigned long long int

void solve() {
    int n; cin >> n;
    vi a(n);

    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++ i) 
    {
        for(int j = 1; j <= i; ++ j) {
            if (a[j] > a[i]) {
                swap(a[j], a[i]);
                }
        }
    }

    for (auto i : a) {
        cout << i << " ";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}