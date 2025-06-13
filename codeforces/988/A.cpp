#include <iostream>
#include <cstring>
using namespace std;
int a[21];
void solve() {
    int ans = 0;
    memset(a, 0, sizeof(a));
    int num;cin >> num;
    for(int i=0; i<num; i++) {
        int x;cin >> x;
        a[x]++;
    }
    for(int i = 1; i <= 20; ++ i) {
        ans += a[i] / 2;
    }
    cout << ans << endl;
}

int main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }
    return 0;
} 