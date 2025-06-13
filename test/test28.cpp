// 辗转相除法
#include <iostream>
#define ll long long 
#define endl "\n"
int gcd(int n, int m) {
    if (n % m == 0) return m;
    return gcd(m, n % m);
}

void solve(){
    std::cout << gcd(1010, 2515) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}