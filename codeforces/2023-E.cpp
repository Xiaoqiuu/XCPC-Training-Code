#include <iostream>
#include <vector>
#define akitama return 0;
using namespace std;

int main() {
    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        int operations = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && p[i] != i) {
                int current = i;
                bool isSimple = false;

                while (!visited[current]) {
                    visited[current] = true;
                    if (p[p[current]] == current) {
                        isSimple = true;  
                    }
                    current = p[current];
                }

                if (!isSimple) {
                    operations++;  
                }
            }
        }

        cout << operations << endl;
    }

    akitama;
}
