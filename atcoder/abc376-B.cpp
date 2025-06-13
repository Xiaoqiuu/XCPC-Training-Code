//Written By Akitama 2024.10
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define akitama return 0
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, q;
    cin >> n >> q;

    int ans = 0;
    char h[n + 1];
    int queries[n + 1];

    for (int i = 1; i <= q; i++) {
        cin >> h[i] >> queries[i];
    }

    int l = 1, r = 2;

    for (int i = 1; i <= q; i++) {
        int s;
        if (l < r) {
            s = l;
        } else {
            s = r;
        }

        int r_wall, l_wall,l_q,r_q;
        if (l < r) {
            r_wall = r - l;
            l_wall = n - r + l;
        } else {
            l_wall = l - r;
            r_wall = n - l + r;
        }

        if(h[i] == 'L'){
            if (queries[i] < s) 
            {
                int r_q = queries[i] - l;
                int l_q = n - queries[i] + l;
                } else {
                    int l_q = l - queries[i];
                    int r_q = n + queries[i] + l;
            }

                if (l_q < r_q && r_q < r_wall) 
                {
                    ans += l_wall;
                    s = queries[i];
                } else if (l_q < r_q && l_q < l_wall) {
                    ans += r_wall;
                    s = queries[i];
                } else {
                    cout << ans << endl;
                    return 0; // 结束程序
                }
            } 

        else
        {
            swap(l_wall, r_wall);
            if (queries[i] < r) {
                int r_q = queries[i] - r;
                int l_q = n - queries[i] + r;
            }
            else {
                    int l_q = r - queries[i];
                    int r_q = n + queries[i] + r;
                }
            }
            if (l_q < r_q && r_q < r_wall) {
                ans += r_wall;
                r = queries[i];
            } else if (l_q < r_q && l_q < l_wall) {
                ans += l_wall;
                r = queries[i];
            } else {
                cout << ans << endl;
                akitama;
            }
        }
        cout << ans << endl;
        akitama;
    }

    /*
    int n, q;cin >> n >> q;
    int ans = 0;
    char h[n + 1];int q[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> q[i];
    }
    int l = 1; r = 2; check = 1 + n / 2;
    for(int i = 1; i <= q; i++) {
        int s = &l; else int s = &r;
        if(l < r){
            r_wall = r - l;
            l_wall = n -r + l;
        }else {
            l_wall = l - r;
            r_wall = n - l + r;
        } if(h[i] == 'R') swap(l_wall, r_wall);
        if (q[i] < s) {
            r_q = q[i] - l;
            l_q = n - q[i] + l;
            if(l_q < r_q && r_q < r_wall) {
                ans += l_wall;
                s = q[i];
            }
            else if(l_q < r_q && l_q < l_wall) {
                ans += r_wall;
                s = q[i];
            }
            else {
                cout << ans << endl;
                akitama;
            }
        }
    }
    cout << ans << endl;

    akitama;
}
    */