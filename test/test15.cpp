#include <iostream>

using namespace std;
using ll = long long;
int main() {
    ll term = 7;
    ll sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += term;
        term *= 10 + 7;
    }
    cout << sum << endl;
    return 0;
}