#include <iostream>
#include <vector>

using namespace std;

signed main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < (int)a.size(); ++ i) {
        cout << a[i] << endl;
    }
    // 迭代器遍历版本
    for (vector<int>::iterator it = a.begin(); it != a.end(); ++ it) {
        cout << *it << endl;
    }
    // begin() end() 是vector容器提供的首尾迭代器
    return 0;
}