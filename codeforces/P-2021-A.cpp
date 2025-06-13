#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
    int t;cin >> t;
    while(t--) {
        int n;cin >> n;
        int a[n];
        for (int i = 0; i<= n; ++ i) {
            cin >> a[i];
        }
        sort(a, a + n);
        
    }
    return 0;
}