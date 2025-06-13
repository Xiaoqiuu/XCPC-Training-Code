#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define akitama  return 0
#define ll long long
#define vi vector<int>

void print(vi v) {
    cout << "Printing vector:\n" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\nPrint finished." <<endl;
}

void test(){
    cout << "Test started." << endl;

    vi v = {4, 5, 2, 3};
    v.erase(v.begin() + 1);
    v.erase(v.begin() + 2);
    
    cout << "Begin: " << *v.begin() << endl;
    print(v);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    akitama;
}