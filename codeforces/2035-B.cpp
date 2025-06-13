#include <iostream>
#define akitama return 0;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = false;
        char ch[n];
        for (int i = 0; i < n; i++) 
            ch[i] = '3';
        
        if (n == 1 || n == 3) {
            cout << -1 << endl;
        } else if (n % 2 == 0) {
            ch[n - 1] = '6';
            ch[n - 2] = '6';
            flag = true;
        } else if (n % 2 == 1) {
            ch[n - 1] = '6';
            ch[n - 2] = '6';
            ch[n - 4] = '6';
            flag = true;
        }

        if (flag) {
            for (int i = 0; i < n; i++) {
                cout << ch[i];
            }
            cout << endl;
        }
    }
    akitama;
}