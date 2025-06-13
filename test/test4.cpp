#include <iostream>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "原始的a数组是：" << endl;
    for(auto i : a) cout << i << " ";
    int b[10];
    memcpy(b, a, sizeof(a));
    cout << endl << "复制后的b数组是：" << endl;
    for(auto i : b) cout << i << " ";
    cout << "\n";

    if(isalpha('a')) cout << "isalpha 函数成功判断char字符是否为字母。" << "\n";

    cout << INT_MIN << endl;


    cout << "1除以10：" << 1/10 << endl;
    return 0;
}