#include <iostream>
#define akitama return 0;
using namespace std;
using ll = long long;
const int N = 1e6 + 7;

int main() {
    int t; cin >> t;ll ans[t];
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        ll ans = 0;
        int a[N] = {0};

        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                int hq; 
                cin >> hq;
                if (hq < 0) { 
                    a[j - k + n] = max(a[j - k + n], -hq);
                }
            }
        }

        for (int j = 0; j <= 2 * n; j++) { 
            ans += a[j];
        }

        cout << ans << endl;
    }
    akitama;
}
