#include <iostream>
#include <algorithm>
#define akitama return 0;
using namespace std;

int main() {
    int t;cin >> t;
    for (int i = 0; i < t; i++) {
        int max = 0, min = 1e6,ans = 0,r = 0;
        int n;cin >> n;int a[n];
        if (n == 1) {
            cin >> r;
            cout << 0 << endl;
        } else{
            for (int j = 0; j < n; j++) {
                cin >> a[j];
            }
            sort(a, a + n);
            int tmp1, tmp2;
            tmp1 = a[0];
            tmp2 = a[n-1];
            a[0] = tmp2;
            a[n - 1] = a[1];
            a[1] = tmp1;
            if(n > 3)
            sort(a + 2, a + n - 1);
            for (int j = 0; j < n; j++) {
                max <a[j]? max = a[j] : max;
                min >a[j]? min = a[j] : min;
                ans += max - min;
            }
            cout << ans << endl;
        }
    }
    akitama;
}