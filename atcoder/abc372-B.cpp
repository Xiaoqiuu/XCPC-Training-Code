#include <iostream>
#include <algorithm>
#include <vector>
#define akitama return 0
#define vec vector

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vec<int> ans;
    ll m;
    cin >> m;
    
    for (int i = 0;; i++) {
        int tmp = 1, cnt = 0;
        while (tmp * 3 <= m) {
            tmp *= 3; 
            cnt++;
        }
        ans.push_back(cnt);
        m -= tmp;
        if (m == 0) break;
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << endl;
    akitama;
}
