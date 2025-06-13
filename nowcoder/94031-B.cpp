#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int main() 
{
    int n;cin >> n;
    ll a[n + 1];ll sum, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll left = a[1], right = a[n] ,middle = sum - left - right;
    int half = n%2==0? n/2 -1 : n/2;
    for (int i = 2; i <= n/2; i++) {
        left += a[i];middle -= a[i];
        if (left < middle && middle > right) ans++;
        right += a[n - i];middle -= a[n - i];
        if (left < middle && middle > right) ans++;
    }
    cout << ans << endl;
    return 0;
}

int check(ll num) {
   ll a ,b ,c;
   
}