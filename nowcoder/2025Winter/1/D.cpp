#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long

void solve() {
    int a = -1, b = -1, c = 0;
    int num, cur_num;cin >> num;
    int a_t = 0, b_t = 0;
    bool isDouble = true;
    for (int i = 1; i <= num; i++) {
        cin >> cur_num;
        if (cur_num != a &&c == 0) {
            a = cur_num;
            a_t++;
            c++;
        } else if (cur_num != b && cur_num != a &&c == 1) {
            b = cur_num;
            b_t++;
            c++;
        } else if(cur_num == a) { a_t++; } else if(cur_num == b) { b_t++; }
        else if (cur_num != a && cur_num != b && c >= 2) {
            isDouble = false;
        }
    }
    if (isDouble && a_t == b_t) {
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