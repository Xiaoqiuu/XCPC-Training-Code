#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;cin >> n;
    char ch[104];cin >> ch;
    for (int i = 0; i < strlen(ch); i++) {
        if (ch[i] == 'n' && ch[i + 1] == 'o' && ch[i + 2] == 't') {
            for (int j = i + 3; j < strlen(ch); j++) {
            ch[j - 3] = ch[j];
            if(j == strlen(ch)-1) ch[j] = '\0';
            }
        }
    }
    for (int i = 0; i < strlen(ch); i++) {
        cout << ch[i];
    }
    return 0;
}