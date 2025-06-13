#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long
#define akitama return 0

void solve() {
    int num;cin >> num;
    int alarm[num];
    int time = 0;
    for(int i = 0;i < num;i ++) {
        cin >> alarm[i];
        if(num >= 3)
        if(i >= 1) {
            if(abs(alarm[i] - alarm[i-1])> (num - 1)*2) {time ++;}
            if(alarm[i] == 2) {time ++;}
        }
    }
    if(num == 2) {
            if(alarm[1] >= 3 && alarm[0] >= 3) {time = 0;} else {time = 100;}
    }
    // int min_val = *min_element(alarm, alarm+num);
    if(time >= num - 1) {cout << "NO\n";} else {cout << "YES\n";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--){
        solve();
    }
    akitama;
}