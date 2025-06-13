#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define akitama return 0

signed main() {
    vector<int> a(7, 0);
    for (int i = 0; i < 7; ++ i) {
        cin >> a[i];
    }

    map<int, int> mp;
    for (int i : a) {
        mp[i]++;
    }

    int f2 = 0, f3 = 0;

    for(auto &i : mp) {
        if(i.second >= 3) {
            f3 ++;
        } else if(i.second == 2) {
            f2 ++;
        }
    }

    if((f3 > 0 && f2 > 0)||(f3 >= 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;   
    }

    
    akitama;
}
// 1 1 1 2 3 4 4 