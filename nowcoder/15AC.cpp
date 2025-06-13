#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int gcd

int main() {  
    int n;  
    cin >> n;  
    vector<int> lei(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> lei[i];  
    }  
    sort(lei.begin(), lei.end());
  
    int ans = 0, right = 0;
    int i = 0; 
    while (i < n) {  
        if (lei[i] > right) {    
            ans += lei[i] - right;  
            right = lei[i] + 1; 
        while (i + 1 < n && lei[i + 1] <= right) {  
            i++;
        }  
        i++;
        }  
    }
    cout << ans << endl;  
    return 0;  
}