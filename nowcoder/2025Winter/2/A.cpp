#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long
#define vi vector<int>
void solve() {
    vi a(7);
    bool flag = true;
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
        if(a[i]!=1 && a[i]!=2 && a[i]!=3 && a[i]!=5 && a[i]!=6 ) {
            flag = false;
        }
    }
    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (t --) {
        solve();
    }
    akitama;
}