#include <iostream>
#include <vector>

using namespace std;

#define akitama return 0
#define vi vector<int>

signed main() {
    vi a = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Fisrt Print Without Revising:\n";
    for (auto i : a) {
        cout << i << '\n';
    }
    a.resize(9);
    cout << a[8] << endl;
    a.push_back(9);
    cout << a[8] << endl;
    cout << a[9] << endl;
    int len = a.size();
    cout << "After pushing back the  number \"9\", now the size of vector is :" << len << endl;
    akitama;
}