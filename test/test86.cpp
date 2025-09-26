#include <iostream>

#define akitama return 0

struct check{
    int operator()(int a, int b) {
        return a * b;
    }
};

signed main() {
    check a;
    std::cout << a(3, 4) << std::endl;
}