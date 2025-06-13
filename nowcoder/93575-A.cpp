#include <iostream>
using namespace std;

int main() {
    int ln; cin >> ln;
    int a[ln];
    for (int i = 0; i < ln; i++) {
        cin >> a[i];
        }
        //判断数组里是否有三个数是相等的
        for (int i = 0; i < ln-2; i++) {
            for (int j = i+1; j < ln-1; j++) {
                for (int k = j+1; k < ln; k++) {
                    if (a[i] == a[j] && a[j] == a[k]) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
        cout << "No" << endl;
                        
    return 0;
}