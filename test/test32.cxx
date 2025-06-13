#include <iostream>
using namespace std;

#define akitama return 0

int test(int a, int b, int& x, int& y) {
    x--;
    y--;
    a++;
    b++;
    return a + b;
}

void solve() {
    int a = 10, b = 10, x = 10, y = 10;
    cout << "Before: a = " << a << ", b = " << b << ", x = " << x << ", y = " << y << endl;
    cout << "Result a + b: " <<  test(a, b, x, y) << endl;
    cout << "After: a = " << a << ", b = " << b << ", x = " << x << ", y = " << y << endl;
}

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout << "Hello, world!" << std::endl;
    solve(); 
    akitama;
}