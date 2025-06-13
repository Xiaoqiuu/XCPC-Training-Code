#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

#define akitama return 0

signed main() {
    string s; cin >> s;
    int n = s.size();
    int A = 0, a = 0;
    for (int i = 0;i < n; ++ i) {
        if(isupper(s[i])) A++;
        else if(islower(s[i])) a++;
    }
    if (A>a) {
        for (int i = 0; i < n; ++ i) s[i] = toupper(s[i]);
    } else for (int i = 0;i < n; ++ i) s[i] = tolower(s[i]);
    cout << s << endl;

    akitama;
}
