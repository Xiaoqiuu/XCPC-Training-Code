#include <iostream>
#include <string>
using namespace std;
#define akitama return 0
signed main() {
    string s = "123456789";
    s.erase(s.end() - 2, s.end());
    cout << s << endl;
    akitama;
}