#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define ll long long int

int main() {
    // string s;
    // // cin >> s;
    // getline(cin, s);
    // cout << s << endl;
    
    ll n = 3; // 0b00000011
    bitset<8> b(n << 1);
    cout << (n << 1) << endl;
    cout << b << endl;
    // BIT位
    return 0;
}