#include <iostream>
using namespace std;

#define akitama return 0

int _gcd(int n, int m) {
    if (n % m == 0) return m;
    else return _gcd(m, n % m);
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    cout << _gcd(a, b) << endl;
    akitama;
}