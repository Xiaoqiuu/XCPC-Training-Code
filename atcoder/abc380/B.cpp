#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<int> A;
    size_t start = 0;
    size_t end = S.find('|', start);
    
    while (end != string::npos) {
        string segment = S.substr(start, end - start);
        if (!segment.empty()) {
            A.push_back(segment.length());
        }
        start = end + 1;
        end = S.find('|', start);
    }

    for (size_t i = 0; i < A.size(); ++i) {
        cout << A[i];
        if (i < A.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
