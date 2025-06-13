#include <iostream>
#include <vector>

using namespace std;

using ll = long long int;
#define akitama return 0
#define vi vector<int>

const int N = 2e5 + 7;
char ch[N];

void solve() {
    int n; cin >> n;
    // ch[0] = '0';
    // for (int i = 1; i <= n; ++ i) {
    //     int l = strlen(ch);
    //     for (int i = 0; i < l; ++ i) {
    //         ch[l+i] = '1' - ch[i] + '0';
    //     }
    // }
    // cout << ch << endl;
    // return;
    // int n; cin >> n;
    auto check = [](int x) {
        int cnt = 0;
        while (x) {
            if (x & 1) {
                ++cnt;
            }
            x >>= 1;
        }
        return cnt;
    };
    for (int i = 0; i < 1 << n; ++ i) {
        if (check(i) & 1) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return;
}

signed main() {
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}