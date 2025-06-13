#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define akitama return 0

signed main() {
    string s;
    getline(cin, s); 
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] >= 'a' && s[i] <= 'w' || s[i] >= 'A' && s[i] <= 'W') s[i] += 3;
        else {
            switch(s[i]) {
                case 'x' : s[i]='a';break;
                case 'y' : s[i]='b';break;
                case 'z' : s[i]='c';break;
                case 'X' : s[i]='A';break;
                case 'Y' : s[i]='B';break;
                case 'Z' : s[i]='C';break;
            }
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++ i)
    if (isupper(s[i])) {
        s[i] = tolower(s[i]);
    } else s[i] = toupper(s[i]);
    cout << s << endl;
    akitama;
}