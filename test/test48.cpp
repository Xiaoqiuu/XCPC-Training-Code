#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long
#define akitama return 0
#define vll vector<long long>

int main() {
    ll n = 0;
    for (int i = 0;; i++) {
        n+= 2025;
        string s = to_string(n);
        bool flag = false;
        for (int j = 0; j < s.size(); j++) {
            if ((s[j] - '0') % 2  == 0 ) {
                flag = false; break; 
            } else flag = true;
        }
        if (flag) {
                cout << n << endl;
                akitama;
            }
    }
    akitama;
}