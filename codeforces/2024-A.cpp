//Written By Akitama
#include <iostream>
#include <cmath>
#define akitama return 0;
using namespace std;
using ll = long long;
int main() {
    int n;cin >> n;
    ll ans[n + 1];
    for (int i = 1; i <= n; i++) {
        ll a, b;cin >> a >> b;
        if (a > b) {
            ans[i] = a;
        } else if(b - a >= a )
            ans[i] = 0;
        else{
            int tmp = a;
            while(tmp < b) {
                b -= abs(b - a) * 2;
                a -= abs(b - a);
                if(a < 0) {
                    ans[i] = 0;
                    break;
                }
            }
            if(a > 0) ans[i] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
        }
    akitama;
}