#include <iostream>
#include <cmath>
#define akitama return 0;
using namespace std;

int main() {
    int n;cin >> n;
    //n张桌子 小朋友数量2n
    int a[2*n + 1];
    for(int i=1;i<=2*n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=2*n;i ++) {
        if(i != a[a[i]] || a[i] == i) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    akitama;
}