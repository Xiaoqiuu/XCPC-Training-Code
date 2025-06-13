#include <iostream>
#include <algorithm>
#include <cstring>
//#include <queue>
//#include <vector>
#define akitama return 0
#define pq priority_queue
#define vec vector

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    char ch[104];cin >> ch;
    for(int i = 0; i < strlen(ch); i++) 
    if(ch[i] != '.')
    cout << ch[i];
    else continue;
    akitama;
}
