#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

void solve() {
    char op[2000000];
    cin >> op;
    if (strlen(op) != 6) {
        cout << "No" << endl;
        return;
    }

    map<char, int> tim;
    for (int i = 0; i < 6; i++)
        tim[op[i]]++;

    char lastChar = op[5];
    if (lastChar == '1' && tim['1'] != 1) {
        cout << "No" << endl;
        return;
    } else if (lastChar == '2' && tim['2'] != 2) {
        cout << "No" << endl;
        return;
    } else if (lastChar == '3' && tim['3'] != 3) {
        cout << "No" << endl;
        return;
    }
    if (tim.size() != 3) {
        cout << "No" << endl;
        return;
    }
    int counts[3] = {0};
    int index = 0;
    for (const auto& pair : tim) counts[index++] = pair.second;
    sort(counts, counts + 3);

    if (counts[0] == 1 && counts[1] == 2 && counts[2] == 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
