/*
 * @Author: Xiaoqiuu/Akitama
 * @Date: 2026-05-18 22:31:54
 * @LastEditors: Xiaoqiuu/Akitama
 * @LastEditTime: 2026-05-22 19:54:56
 * @FilePath: /workspace/codeforces/2230/A.cpp
 * @Description: XCPC | 408 | Unity | Agents
 */
#include<iostream>
#define ll long long int

signed main() {
    int _; std::cin >> _;
    while (_--) {
        ll n, a, b; std::cin >> n >> a >> b;
        if (n <= 2) {
            std::cout << (a * n < b? a * n : b) << std::endl;
            continue;
        }
        if (3 * a < b) {
            std::cout << n * a << std::endl;
        } else {
            std::cout << ((n % 3)? (n / 3) * b + ((n % 3) * a):(n / 3)* b) << std::endl;
        }
    }
}