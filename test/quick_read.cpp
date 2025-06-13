#include <iostream>
#include <cstring>
using namespace std;
#define oiye return 0;
using ll = long long;
using i128 = __int128;

i128 read() {
    char ch[100000];
    i128 num = 0;
    scanf("%s", ch);
    for (int i = 0; i < strlen(ch); i++) {  
        num *= 10;  // 
        num += ch[i] - '0';  
    }
    return num;
}

void print(i128 num) {
    if (num < 10) {  
        putchar(num + '0');  
        return;  
    }
    print(num / 10);  
    putchar(num % 10 + '0'); 
}

int main() {
    print(read());
    oiye;
}
