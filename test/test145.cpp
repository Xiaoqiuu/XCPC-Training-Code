#include <iostream>

#define akitama return 0

using ll = long long int;

signed main() {
    int n; std::cin >> n;
    ll k; std::cin >> k;
    k += 100;
    k -= n;
    std::cout << k << std::endl;
    akitama;
}