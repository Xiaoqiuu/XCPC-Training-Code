#include <iostream>
#include <unordered_map>
#include <vector>
#define akitama return 0
using namespace std;
using ll = long long;
using up = unordered_map<int, int>; // 
using pr = pair<int, int>;

int main() {
    unordered_map<int, int> mp = { 
        pr(1, 2),
        pr(3, 4)
    };
    cout << "第一种遍历方法是引用传递遍历："  << endl;
    for (auto kv : mp) {
        cout << kv.first << " " << kv.second << endl;
    }

    cout << "第二种遍历方法是引用传递遍历："  << endl;
    for (const pair<int, int>& kv : mp)
        cout << kv.first << " " << kv.second << endl;


    cout << "第三种遍历方法使用了迭代器iterator遍历："  << endl;
    for (unordered_map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it -> first << " " << it -> second << endl;
    }

    vector<pair<int, int>> vec = {
        pr(1, 2),
        pr(3, 4),
        pr(5, 6)
    };
    for(int i = 0;i < vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    cout << 7 / 2 << endl;
    return 0;
}