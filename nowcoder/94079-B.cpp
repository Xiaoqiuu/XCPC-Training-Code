#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int main() {
    //n个点 1-n个符号
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m;cin >> n >> m;
        int r_num = 0;//兔子数量
        if (n == 1 || n == 2) {
            cout << 0 << endl;
        } else if (n == 3) {
            m >= 2?cout << 1 << endl : cout << 0 << endl;
        } else if (n >= 4) {
            r_num = 3;
            for (int i = 4; i <= n; ++ i) {
                if()
                r_num += i - 3;
            }


    return 0;
}
