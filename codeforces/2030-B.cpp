#include <iostream>
#include <cstring>
#define akitama return 0;
using namespace std;
const int N = 2e5 + 9;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;cin >> n;
        if (n == 1) cout << "0" << endl;
        else if(n == 2)cout << "01" << endl;
        else{
            cout << "01";
            for(int j = 1; j <= n - 2; ++ j) {
                cout << "0";
            }
            cout << endl;
        }
    }
    akitama;
}