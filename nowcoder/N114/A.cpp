#include <bitsd/stdc++.h>
using namespace std;

#define akitama return 0

signed main(){
    int t = 1;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        // 5
        for (auto i : a)
        {
            if (i == 0) cout << 0 << " ";
            else {
                i - 1 >5? cout << 5 << " " : cout << i - 5 << " ";
            }cout << endl;
        }
    }
    akitama;
}