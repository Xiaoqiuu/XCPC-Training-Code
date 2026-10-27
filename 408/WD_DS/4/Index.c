#include <stdbool.h>
#define MaxLength 255
typedef struct {
    char ch[MaxLength];
    int length;
} SString;

int StrLength(SString S) {
    return S.length;
}

// 求子串：通过指针 sub 返回串 S 的第 pos 个字符起长度为 len 的子串
bool SubString(SString *sub, SString S, int pos, int len) {
    // 越界及合法性校验
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        sub->ch[i] = S.ch[pos + i - 1]; // 逻辑位序 pos 映射到物理下标 pos - 1
    }
    sub->length = len;
    return true;
}

// 串判等
bool Equal(SString S, SString T) {
    if (S.length != T.length) return false;
    for (int i = 0; i < S.length; ++i) {
        if (S.ch[i] != T.ch[i]) return false;
    }
    return true;
}

// 定位操作：朴素模式匹配（基于子串提取与判等）
int Index(SString S, SString T) {
    int n = StrLength(S), m = StrLength(T);
    SString sub;
    
    for (int i = 1; i <= n - m + 1; ++ i) {
        SubString(&sub, S, i, m); // 传入 sub 的地址以回传结果
        if (Equal(sub, T)) {
            return i; // 匹配成功，返回主串中的逻辑位序
        }
    }
    return 0; // 匹配失败
}

int _index(SString S, SString T) {
    int n = S.length, m = T.length;
    int i = 1, j = 1;
    for (; i <= n && j <= m; ++ i, ++ j) {
        if (S.ch[i] != T.ch[j]) {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) return i - T.length;
    return 0; // 
}