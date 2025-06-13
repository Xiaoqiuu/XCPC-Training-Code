#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<bool> trees(m + 1, true);
    vector<bool> grass(m, true);

    for (int i = 0; i < n; ++i) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            for (int j = l; j < r; ++j) {
                grass[j - 1] = false;
            }
        } else if (type == 2) {

            for (int j = l; j <= r; ++j) {
                trees[j] = false;  
            }
            for (int j = l; j < r; ++j) {
                grass[j - 1] = false; 
            }
        }
    }

    int r_trees = 0;
    int r_grass = 0;

    for (int i = 1; i <= m; ++i) {
        if (trees[i]) {
            r_trees++;
        }
    }

    for (int i = 0; i < m - 1; ++i) {
        if (grass[i]) {
            r_grass++;
        }
    }

    cout << r_trees << " " << r_grass << endl;
    return 0;
}
