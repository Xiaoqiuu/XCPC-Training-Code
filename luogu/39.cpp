#include <iostream>
#include <cstring>
#include <set>
//#define arr_len(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
//int ans[102];

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    set<int> se;

    int x1 = a + b;
    int x2 = a - b;

    if (x1 >= 0 && x1 <= n) {
        se.insert(x1);
    }
    if (x2 >= 0 && x2 <= n) {
        se.insert(x2);
    }

    if (!se.empty()) {
        for (int ans : se) {
            cout << ans << " ";
        }
        cout << endl;
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}