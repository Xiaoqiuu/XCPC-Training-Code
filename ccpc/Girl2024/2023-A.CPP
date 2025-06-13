#include <iostream>
using namespace std;

int main() {
    int q1, q2, q3, q4, q5;
    cout << "0 0 1" << endl;
    cin >> q1;
    cout << "0 1 0" << endl;
    cin >> q2;
    cout << "1 0 0" << endl;
    cin >> q3;
    cout << "0 1 1" << endl;
    cin >> q4;
    cout << "4 5 6" << endl;
    cin >> q5;
    for (int a = 0; a <= 10; ++a) {
        for (int b = 0; b <= 10; ++b) {
            for (int c = 0; c <= 10; ++c) {
                int count = 0;
                if (c == q1) count++;
                if (b == q2) count++;
                if (a == q3) count++;
                if (b + c == q4) count++;
                if (4*a + 5*b + 6*c == q5) count++;
                if (count >= 3) {
                    cout << a << " " << b << " " << c << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
