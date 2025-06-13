//A Two Screens By Akitama
#include <iostream>
#include <cstring>
#define akitama return 0
using namespace std;

int main() {
    int q; 
    cin >> q; 
    int ans[q]; 
    int tmp = q; 
    while (q--) {
        char c1[105], c2[105];
        cin >> c1 >> c2;
        int len1 = strlen(c1), len2 = strlen(c2);
        int min_len = len1 < len2 ? len1 : len2;
        int max_len = len1 > len2 ? len1 : len2;
        
        bool isDifferent = false; 
        int op = 0;
        for (int i = 0; i < min_len; i++) {
            if (c1[i] != c2[i]) {
                i != 0 ? ans[tmp - q - 1] = (i + 1 + len1 - i + len2 - i) : ans[tmp - q - 1] = (len1 + len2);
                isDifferent = true;
                break; 
            }
        }

        if (!isDifferent) {
            len1 + len2 < max_len + 1 ? ans[tmp - q - 1] = len1 + len2 : ans[tmp - q - 1] = max_len + 1; 

        }
    }
    for (int i = 0; i <= tmp - 1; i ++) {
        cout << ans[i] << endl;
    }

    akitama;
}
