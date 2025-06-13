#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define akitama return 0

signed main() {
    int n;cin >> n;
    string s = "";
    for (int i = 0; i < n; i ++) {
        s += "-";
    }
    if (n % 2 == 0) s[n/2-1] = '=',s[n/2]= '=';
    else s[n/2] = '=';

    cout << s << endl;
    akitama;
}