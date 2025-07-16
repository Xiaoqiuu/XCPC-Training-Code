#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getNext(string p, vector<int> &next) {
    int m = p.length();
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < m - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}
// KMP算法模板
void kmp(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<int> next(m);
    getNext(p, next);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && p[j] != s[i]) {
            j = next[j - 1];
        }
        if (j < m && p[j] == s[i]) {
            j++;
        }
        if (j == m) {
            cout << "pattern found at " << i - m + 1 << endl;
            j = next[j - 1];
        }
    }
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string p = "vw";
    kmp(s, p);
    return 0;
}
