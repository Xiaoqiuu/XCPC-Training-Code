#include <iostream>
#include <cstring>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[2*n];
    set<int> s;
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    ans = (2*n - s.size() + 1) / 2;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}