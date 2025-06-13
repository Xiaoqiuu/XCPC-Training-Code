#include <iostream>
#include <vector>

using namespace std;
#define akitama return 0

#define vi vector<int>

void solve(){
    vi vec  = {2, 3, 1, 1, 4, 5, 4, 4, 5, 8, 7, 6, 1, 8, 10, 9};
    sort(vec.begin(), vec.end());
    vector<int>::iterator last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    for(int i : vec){
        cout << i << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);

    solve();
    akitama;
}