#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    // 1 1 2 3 5
    // if (n == 1) return 1;
    // if (n == 2) return 1;
    if (n <= 2) return 1;
    else return f(n - 1) + f(n - 2);
}

// for (int i = 1; i <= n; ++ i) {

// }

signed main() {
    cout << f(5);
    // cout << d_sum(100);

    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid == target) // 
        else if (mid < target) { l = mid + 1; }
        else r = mid - 1;
    }
    

}