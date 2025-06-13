// aSS

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define akitama return 0
#define ll long long int
#define ull unsigned long long int

const int N = 1e5 + 7;



signed main() {
    ull us = 0;

    vector<string> v(N);
    for (auto& i : v) i = "haha";

    cout << "vector<bool> is not recommended to use. Please try to use bitset instead." << endl;

    // vector<bool> b(N);
    // for (auto& i = b.begin(); i!= b.end(); ++ i) {
        
    // }
        // cout << i;

    // bitset

    bitset<8> b = {0b00000010};
    bitset<8> num1(32);
    for (int i = 0; i < 2; ++ i)
    //b &= 1;

    cout << b << endl;
    cout << "The binary representation of ""<< b <<"" is: " << b.to_ulong() << endl;
    cout << "The binary representation of 32 is: " << num1 << endl;
    akitama;
}

// a string is an object
// an int is a value
// you can give a pointer to &i
// but not a value to &i

