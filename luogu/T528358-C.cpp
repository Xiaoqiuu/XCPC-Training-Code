#include <iostream>
#include <cmath>
#define akitama return 0;
using namespace std;

int main() {
    //开课星期w 开课间隔d
    //课程数量n
    int n;cin >> n;
    int ans = 1e4;
    for (int i = 0; i < n; i++) {
        int w, d;cin >> w >> d;
        ans > d * 7 - abs(6 - w)? ans = d * 7 - abs(6 - w) : ans;
    }
    cout << ans << endl;
    akitama;
}