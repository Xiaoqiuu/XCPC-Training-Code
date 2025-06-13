#include <iostream>
#include <bitset>
using namespace std;
#define i32 int
#define ll long long
#define ul unsigned long long
#define akitama return 0
int main(){
    ul a = 6;
    cout << a << endl;
    cout << ~a << endl;
    cout << (bitset<64>)a << endl;
    cout << (bitset<64>)~a << endl;
    akitama;
}
