#include <iostream>
#include <vector>
#include <string>
using namespace std;

char getCharAt(const string& s, long long k) {
    long long len = s.size();
    while (k >= len) {
        long long half = len;
        len *= 2; // Double the length for next generation
        if (k < len / 2) {
            len /= 2; // Only halve if the position is in the first half
        } else {
            k -= len / 2; // Adjust position to reflect the right half
            k--; // Move to reflect the character preceding in original pattern
            len /= 2;
        }
    }
    return s[k];
}

int main() {
    string s;
    cin >> s;
    long long q;
    cin >> q;
    vector<long long> ks(q);
    for (int i = 0; i < q; i++) {
        cin >> ks[i];
        ks[i]--; // Convert to 0-based index
    }

    for (long long k : ks) {
        char res = getCharAt(s, k);
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}
