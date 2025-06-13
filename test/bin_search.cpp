#include <iostream>
#include <algorithm>
#define akitama return 0;
using namespace std;

bool bin_search(int arr[], int key) {
    int low = 0, high = 9;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false; 
}

int main() {
    int arr[10] = {9, 39, 20, 13, 27, 1, 88, 30, 7, 2};
    sort(arr, arr + 10);
    cout << "请输入查询的数据: ";
    int key;cin >> key;
    bool flag = bin_search(arr, key);
    if (flag) {
        cout << "在数组中找到了：" << key << endl;
    } else {
        cout << "并没有没找到：" << key << endl;    
    }
    akitama;
}