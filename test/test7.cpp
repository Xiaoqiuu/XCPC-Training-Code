#include <iostream>

using namespace std;

template<typename T>
struct B {
    int var;
};
template<typename T> 
struct D : B<T> {
    D() {
        this->var = 10;
    }
};

int main() {
    D<int> d;
    cout << "1 :" << endl;
    cout << d.var << endl;
    return 0;
}