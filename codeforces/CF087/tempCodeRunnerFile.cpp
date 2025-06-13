#include <iostream>
using namespace std;
using ll = long long;

void solve() {
    int num;cin >> num;
    if(num == 1) {
        int j;cin >> j;
        cout << 0 << endl;
    } else if(num == 2) {
        int a, b;cin >> a >> b;
        a > b? cout << 2 << endl : cout << 0 << endl;
    }
    else {
        int a[num + 1];
        for(int i = 1;i <= num; ++ i) {
            cin >> a[i];
        }
        int tar = a[num/2], tar_cnt = 0;
        for (int i = 1; i <= num; ++ i) {
            if(a[i] == tar) ++ tar_cnt;
        }
        cout << num - tar_cnt << endl;
    }
}

int main() {
    int t;cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}