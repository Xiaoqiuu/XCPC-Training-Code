#include <iostream>
#include <vector>
using namespace std;

#define akitama return 0

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    if (a.size() == 1) {
        cout << (4 - a[0]) % 4 << endl;
    }
    long long ans = 0;
    for (int i = 1; i < n; ++ i) {
        if (a[i] == a[i-1]) continue;
        else ans += abs(a[0]-a[i]);
    }
    cout << ans << endl;
    akitama;
}