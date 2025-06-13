#include <cmath>
#include <iostream>
#define akitama return 0;
using namespace std;

using ll = long long;
using ld = long double;

void math() {
    ll test;ld test_1;
    test = pow(2,10);
    cout << "pow是用来计算x的y次方幂。" << test << endl;
    test = abs(-161.7555);
    cout << "abs是用来计算绝对值。" << test << endl;
    test = cos(pow(abs(0), 2));
    cout << "cos是用来计算余弦值。" << test << endl;
    test_1 = exp(2);
    printf("%.10lf", test_1);
}

int main() {
    math();
    akitama;
}