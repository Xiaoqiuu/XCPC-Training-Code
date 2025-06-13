#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define akitama return 0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec = {5, 2, 8, 1, 4};
    sort(vec.begin(), vec.end(), [](int a, int b){
        return a > b;
    });

    for(auto &i : vec) cout << i << " ";
    cout << endl;

    akitama;
}