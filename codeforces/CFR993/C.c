#include <stdio.h>

#define akitama return 0

signed main() {
    int _;
    scanf("%d\n", &_);
    while (_-- > 0) {
        int t, a, b, c;
        scanf("%d%d%d%d", &t, &a, &b, &c);
        int row1 = a<=t? a : t, row2 = b<=t? b : t;
        if (row1 != t && c != 0) {
            int tmp = row1;
            row1 += c >= t - row1? t - row1 : c;
            c -= t - tmp > c? c : t - tmp;
        }
        if (row2 != t && c != 0) {
            
        }
    }
    akitama;
}