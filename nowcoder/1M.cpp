#include <bits/stdc++.h>  
using namespace std;  
  
const int MAXN = 2e5 + 5;  
  
vector<int> cat[MAXN];  
vector<int> flag[MAXN];  
bool used[MAXN];  
  
int main() {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
  
    int n;  
    cin >> n;  
  
    vector<int> a(n), b(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> a[i];  
    }  
    for (int i = 0; i < n; ++i) {  
        cin >> b[i];  
        cat[b[i]].push_back(a[i]);  
        flag[b[i]].push_back(i);  
    }  
  
    int ans = -1;  
    for (int i = 0; i < MAXN; ++i) {  
        if (cat[i].empty()) continue;  
  
        sort(cat[i].begin(), cat[i].end());  
        bool possible = true;  
        vector<int> n_flag(n, -1);  
        int count = 0;  
  
        for (int j = 0; j < cat[i].size(); ++j) {  
            if (cat[i][j] == a[flag[i][j]]) {  
                possible = false;  
                break;  
            }  
  
            bool found = false;  
            for (int k = 0; k < cat[i].size(); ++k) {  
                if (n_flag[k] == -1 && cat[i][k] != a[flag[i][j]]) {  
                    n_flag[k] = flag[i][j];  
                    found = true;  
                    break;  
                }  
            }  
  
            if (!found) {  
                for (int k = 0; k < cat[i].size(); ++k) {  
                    if (cat[i][k] == a[flag[j]]) {  
                        swap(flag[j], flag[k]);  
                        count++;  
                        break;  
                    }  
                }  
            }  
        }  
  
        if (possible) {  
            if (ans == -1 || count < ans) {  
                ans = swap_count;  
            }  
        }  
    }  
  
    cout << ans << endl;  
  
    return 0;  
}