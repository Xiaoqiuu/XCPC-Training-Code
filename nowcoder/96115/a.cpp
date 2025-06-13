#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    ll a, b;
    cin >> a >> b;
    cout << max(a,b) + abs(a-b) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 2^10 << endl;
    solve();
    return 0;
}