#include <iostream>
#include <vector>
using namespace std;

#define akitama return 0
// #define ll long long int
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>

constexpr int N = 1e6 + 7;
vi b(N);

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int cnt = 1;
    if (m%k==0) {
        if (!(k%2)) {
            for (int i = 1; i <= k; i += 2) {
                b[i] = i + 1, b[i+1] = i;
            }
        } else {
            for (int i = 1; i <= k - 3; i += 2) {
                b[i] = i + 1, b[i+1] = i;
                b[k-2] = k - 1, b[k-1] = k, b[k] = k - 2;
            }
        }
        for (int i = 1; i <= n; ++ i) {
            if (i%2==1) {
                for (int j = 1; j <= m; ++ j) {
                    if (j%k==0) {
                        cout << k;
                    } else {
                        cout << j % k;
                    } cout << " ";
                }
            } else {
                for (int j = 1; j <= m; ++ j) {
                    if (j%k==0) {
                        cout << b[k];
                    } else {
                        cout << b[j%k];
                    } cout << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cout << cnt << " ";
            ++cnt;
            if (cnt > k) {
                cnt -= k;
            }
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) { solve(); _--; }
    akitama;
}