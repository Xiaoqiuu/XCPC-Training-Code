#include <iostream>
#include <bitset>
using namespace std;
#define akitama return 0
signed main() {
    int n; cin >> n;
    if (n & 2) cout << "3\n";
    else cout << "impossible.\n";
    cout << "-------------\n"; 
    // 00000000
    // 00000001

    // 00011101
    // 00000010
    bitset<8> b(n);
    cout << "The num "<< n <<" : ";
    cout << b << endl;
    akitama;
}
always add a blank line after your code
good
