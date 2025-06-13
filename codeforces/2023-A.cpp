#include <iostream>
#define akitama return 0;
using namespace std;

int main() {
    int n;cin >> n;
    bool ans[n + 1];
    for (int i = 1; i <= n; ++ i) {
        int num;cin >> num;
        num % 2 ==0?ans[i] = true:ans[i] = false;
    }
    for (int i = 1;i <= n; ++ i) {
        if(ans[i])cout << "Sakurako" << endl;
        else cout << "Kosuke" << endl;
    }
    akitama;
}