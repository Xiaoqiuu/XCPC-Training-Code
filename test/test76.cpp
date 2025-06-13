#include <iostream>
using namespace std;

signed main() {
    int a[1] = {2};
    if (a[-1]) cout << "2";
    else cout << 3 << endl;
    cout << a[-1] << endl;
    return 0;
}