#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n;cin >> n;
    int a[n + 1];
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i >= 2) {
            if(a[i - 1] > a[i] && a[i] - a[i - 1] == 1) {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                cout << a[i] << endl;
            } else if(a[i - 1] > a[i] && a[i] - a[i - 1] != 1) {
                flag = false;
            }
            if (a[i - 1] >= a[i]) flag = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}