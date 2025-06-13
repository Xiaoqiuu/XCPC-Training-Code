//Written By Akitama
#include <iostream>
#include <cmath>
#define akitama return 0;
using namespace std;
using ll = long long;
int main() {
    int n;cin >> n;
    ll ans[n+1];
    for(int i=1;i<=n;i++){
        int len;ll need;cin >> len >> need;
        ll mah[len + 1];
        for (int w = 1;w <= len;w++)
        {
            cin >> mah[w];
            if (mah[w] >= need) {
                ans[i] = need;
                break;
            }
        }
        sort (mah + 1, mah + len + 1);
    }
    akitama;
}