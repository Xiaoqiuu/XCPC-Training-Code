#include <iostream>
#include <vector>
#include <algorithm>
#define akitama return 0

signed main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;
    std::sort(a.begin(), a.end());
    for (auto &i : a) std::cout << i << " ";
    std::cout << std::endl;
    akitama;
}