#include <iostream>
#include <cassert>
#include <climits>
using namespace std;
#define i32 int
void test(int x) {
    assert(x > 0);
}

int main() {
    i32 a = 4, b = INT_MIN;
    cout << "Assert Testing..." << endl;
     cout << "Testing a..." << endl;
    test(a);
    cout << "Testing b:INT_MIN..." << endl;
    test(b);
    cout << "Done." << endl;
    return 0;
}