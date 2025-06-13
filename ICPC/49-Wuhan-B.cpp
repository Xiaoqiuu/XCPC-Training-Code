//2026
#include <iostream>
#include <utility>
#define akitama return 0
#define pir pair<int, int>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
    int t;cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
        if((k == x && k == y)|| (k < x && k < y)){
            //(Ax == Bx && Cy == Dy) (Ay == By && Cx == Dx)
            Ax = 0, Ay = 0,
            Cx = 0, Cy = 0;
            Bx = x, By = 0;
            Dx = 0, Dy = y;
        } else {
        //(Bx - Ax) ^ 2 + (By - Ay) ^ 2 = k^2
            Ax = 0, Ay = 0,
            Bx = min(x, y), By = min(x, y);
            Cx = 0, Cy = min(x, y);
            Dx = min(x, y), Dy = 0;
        }
        cout << Ax << " " << Ay << " " << Bx << " " << By << endl << Cx << " " << Cy << " " << Dx << " " << Dy << endl;
    }
    return 0;
}