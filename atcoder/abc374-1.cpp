#include <iostream>
#include <cstring>
#define akitama return 0
using namespace std;

int main() 
{
    char ch[50];
    cin >> ch;
    int len = strlen(ch);
    if (ch[len - 1] == 'n' && ch[len - 2] == 'a' && ch[len - 3] == 's')
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    akitama;
}