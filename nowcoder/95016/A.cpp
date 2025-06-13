#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define akitama return 0
using ll = long long;
using ld = long double;

int main() {
    ll len, a = 0, A = 0;
    cin >> len;
    char ch[10009]; cin >> ch;
    char ans[10009];

    for (int i = 0; i < len; i++) {
        if(ch[i] >= 'a' && ch[i] <= 'z') a++;
        else if(ch[i] >= 'A' && ch[i] <= 'Z') A++;
    }

    int j = 0;
    for (int i = 0; i < len; i++){
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            ans[j] = ch[i];
            j++;
        }
    }
    for (int i = 0; i < len; i++){
        if(ch[i] >= '0' && ch[i] <= '9'){
            ans[j] = ch[i];
            j++;
        }
    }
    for (int i = 0; i < len; i++) {
        if(ch[i] >= 'A' && ch[i] <= 'Z'){
            ans[j] = ch[i];
            j++;
        }
    }

    ans[j] = '\0';
    cout << ans;

    akitama;
}
