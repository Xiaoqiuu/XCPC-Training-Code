#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, p;
        std::cin >> n >> k >> p;
        if (k < -n * p || k > n * p) {
            std::cout << -1 << std::endl;
            continue;
        }
        if (k == 0) {
            std::cout << 0 << std::endl;
            continue;
        }
        int operations = std::abs(k) / p;
        if (std::abs(k) % p != 0) {
            operations++;
        }
        std::cout << operations << std::endl;
    }
    return 0;
}