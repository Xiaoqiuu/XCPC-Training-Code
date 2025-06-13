#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

int main() {
    int n;cin >> n;
    for (int i =1; i<=n; i++) {
        ll a, b;cin >> a >> b;
        ll c, d;cin >> c >> d;
        ll me, him;
        a%b == 0 ? me = a/b : me = a/b + 1;
        c%d == 0 ? him = c/d : him = c/d + 1;
        if(me<him)cout << me - (him - 1) << " ";
        else cout << c - a << endl;
    }
    cout << endl;
    return 0;
}