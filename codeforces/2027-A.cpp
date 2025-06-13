#include <iostream>
#define akitama return 0;
using namespace std;

int main() {
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int r = 0, w = 0;
        for (int i = 1; i <= n; i++) {
            int a, b;cin >> a >> b;
            if(a > r) r = a;
            if(b > w) w = b;
        }
        cout << r* 2 + w * 2 << endl;
    }
    akitama;
}