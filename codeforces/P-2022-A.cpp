#include <iostream>
#define akitama return 0;
using namespace std;
using ll = long long;

int main() {
    int t;cin >> t;
    while (t--) {
        int num, row, rest = 0;
        cin >> num >> row;
        int ans = 0, odd = 0, cp = 0;
        for (int i = 0; i < num; ++ i) {
            int mem;
            cin >> mem;
            cp += mem / 2;
            if (mem % 2)
                odd++;
        }
        ans += cp * 2;
        int rl = row - cp;
        ans += min(odd, rl * 2 - odd);
        cout << ans << endl;
    }
    akitama;
}