#include <iostream>
using namespace std;

int main() {
    int q1, q2, q3, q4, q5;
    int a, b, c;
    cout << "1 1 1" << endl;
    cin >> q1;
    cout << "1 1 0" << endl;
    cin >> q2;
    cout << "1 0 1" << endl;
    cin >> q3;
    cout << "0 1 1" << endl;
    cin >> q4;
    cout << "1 0 0" << endl;
    cin >> q5;
    for (int i = 0; i < 5; ++i) {
        if (i == 0) {
            if (q2 == q3 + q4) {
                a = q1 - q4;
                b = q1 - q3;
                c = q1 - q2;
                break;
            }
        } 
        else if (i == 1) {
            if (q3 == q2 + q4) {
                a = q1 - q4;
                b = q1 - q2;
                c = q1 - q3;
                break;
            }
        } 
        else if (i == 2) {
            if (q4 == q2 + q5) {
                a = q2 - q3;
                b = q1 + q5;
                c = q2 + q4;
                break;
            }
        }
    }

    cout << a << " " << b << " " << c << endl;
    return 0;
}
