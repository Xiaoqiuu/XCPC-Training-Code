#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;

    vector<string> matrix(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> matrix[i];
    }

    int max_count = 0;
    pair<int, int> top_left, bottom_right;

    for (int r1 = 0; r1 < m; ++r1) {
        for (int c1 = 0; c1 < n; ++c1) {
            if (matrix[r1][c1] == '*') continue; 
            for (int r2 = r1; r2 < m; ++r2) {
                for (int c2 = c1; c2 < n; ++c2) {
                    if (matrix[r2][c2] == '*') continue;
                    
                    bool valid = true;
                    int count = 0;
                    for (int r = r1; r <= r2; ++r) {
                        for (int c = c1; c <= c2; ++c) {
                            if (matrix[r][c] == '*') {
                                valid = false;
                                break;
                            }
                            count++;
                        }
                        if (!valid) break;
                    }
                    
                    if (valid && count > max_count) {
                        max_count = count;
                        top_left = {r1 + 1, c1 + 1}; 
                        bottom_right = {r2 + 1, c2 + 1};
                    }
                }
            }
        }
    }

    if (max_count > 0) {
        cout << top_left.first << " " << top_left.second << " ";
        cout << bottom_right.first << " " << bottom_right.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
