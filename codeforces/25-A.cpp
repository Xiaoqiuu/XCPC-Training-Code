#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
#define akitama return 0
signed main() {
    int n; cin >> n;
    vector<int> a(n+1, 0);
    int n1 = 0, n0 = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (a[i] & 1) n1++;
        else n0++;
    }
    for (int i = 1; i <= n; ++ i) {
        if (n0 < n1) {
            if (!(a[i] & 1)) {
                cout << i << endl;
                return 0;
            }
        }
        else if (n0 > n1) {
            if (a[i] & 1) {
                cout << i << endl;
                return 0;
            }
        }
    }
    
    akitama;
}