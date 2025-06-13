#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; 
    cin >> N >> K;
    string S; 
    cin >> S;
    
    vector<int> lp0(N+1), hp0(N+1), lp1(N+1), hp1(N+1);
    lp0[N] = 0; hp0[N] = 0; lp1[N] = 0; hp1[N] = 0;
    for(int i = N-1; i >= 0; i--){
        
        {
            char c = S[i];
            int lo, hi;
            if(c == 'o'){
                
                int L = lp1[i+1], H = hp1[i+1];
                if(L == INF) { lo = INF; hi = -1; }
                else { lo = 1 + L; hi = 1 + H; }
            }
            else if(c == '.'){
                int L = lp0[i+1], H = hp0[i+1];
                lo = L; hi = H;
            }
            else{ 
                int lo1 = INF, hi1 = -1;
                
                int L1 = lp0[i+1], H1 = hp0[i+1];
                lo1 = min(lo1, L1);
                hi1 = max(hi1, H1);
                
                int L2 = lp1[i+1], H2 = hp1[i+1];
                if(L2 != INF){
                    lo1 = min(lo1, 1 + L2);
                    hi1 = max(hi1, 1 + H2);
                }
                lo = lo1; hi = hi1;
            }
            lp0[i] = lo; hp0[i] = hi;
        }
        
        {
            char c = S[i];
            if(c == 'o'){
                lp1[i] = INF; hp1[i] = -1; 
            }
            else if(c == '.'){
                lp1[i] = lp0[i+1]; hp1[i] = hp0[i+1];
            }
            else{ // '?'
                lp1[i] = lp0[i+1]; hp1[i] = hp0[i+1];
            }
        }
    }
    
    auto gr = [&](int mode) -> string {
        string res = "";
        int st = 0, r = K;
        for (int i = 0; i < N; i++){
            char c = S[i];
            if(c == 'o' || c == '.'){
                res.push_back(c);
                if(c == 'o'){
                    st = 1;
                    r--;
                } else {
                    st = 0;
                }
            }
            else{
                char ch;
                if(mode == 0){
                    
                    int L, H;
                    if(st == 0){ L = lp0[i+1]; H = hp0[i+1]; }
                    else { L = lp1[i+1]; H = hp1[i+1]; }
                    if(r >= L && r <= H){
                        ch = '.';
                        st = 0;
                    }
                    else{
                        
                        ch = 'o';
                        st = 1;
                        r--;
                    }
                }
                else{
                    
                    if(st == 0 && r > 0){
                        int L = lp1[i+1], H = hp1[i+1];
                        if(r-1 >= L && r-1 <= H){
                            ch = 'o';
                            st = 1;
                            r--;
                        }
                        else{
                            ch = '.';
                            st = 0;
                        }
                    }
                    else{
                        ch = '.';
                        st = 0;
                    }
                }
                res.push_back(ch);
            }
        }
        return res;
    };
    string a = gr(0), b = gr(1);
    string ans = "";
    for(int i = 0; i < N; i++){
        if(a[i] == b[i])
            ans.push_back(a[i]);
        else
            ans.push_back('?');
    }
    cout << ans << "\n";
    return 0;
}
