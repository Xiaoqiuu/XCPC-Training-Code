#include <iostream>
#include <climits>
#define INF INT_MAX
#define akitama return 0;
using namespace std;
const int N = 1e9 + 7;
int main() {
    int t;cin >> t;
    while (t--) {
        int n, ans =INF, p[N] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;cin >> x;
            p[x]++;
        }
        for (int i = 1; i <= N; i++) {
            if (p[i] >= 3) {
                ans = min(ans, i * 3);
            }
        }
        if (ans == INF) {
            cout << "No" << endl;
            } else {
                cout << "Yes\n" << ans << endl;
            }
    }
    akitama;
}