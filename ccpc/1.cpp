#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
const int N = 1e2 + 6;
ll F[N];
ll ans[N];

//变量名称：酸度V 辣度S 香菜含量C
//风味值F的计算公式： F= V x S + C

int main()
{
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    //输入行数T
    //ll ans = 0;
    int T = 0;
    scanf("%d", &T);
    //输入风味值F
   for (int i = 1; i <= T; ++ i) {
       scanf("%lld", &F[i]);
   }
    //计算V,S,C组合计算出F的组合数
    for (int i = 1; i <= T; ++ i) {
        ans[i] = 0;
        ll num = (ll)sqrt(F[i]);// V和S的最大值 对F进行开方处理
        for (ll j = 0; j <= num; ++ j) {
            //V值从1自增到sqrt(F[i])
            for (ll k = 0; k <= num; ++ k) {
                //S值从1自增到sqrt(F[i])
                ll b_num = F[i] - j * k;
                if (b_num >= 0) {
                    ans[i] ++;
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= T; ++ i)
    printf("%lld\n", ans[i]);
    return 0;
}