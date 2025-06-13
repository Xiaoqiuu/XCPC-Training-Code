#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string input, lowercase, uppercase, digits;
    cin >> input;
    
    for (char c : input) {
        if (islower(c)) {
            lowercase += c;
        } else if (isupper(c)) {
            uppercase += c;
        } else if (isdigit(c)) {
            digits += c;
        }
    }
    
    cout << lowercase << digits << uppercase << endl;
    return 0;
}