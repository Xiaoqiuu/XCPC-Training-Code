#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define akitama return 0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Y, M;
    cin >> N >> Y >> M;
    
    unordered_set<ll> u_id;
    
    for(int i=0; i<N; ++i){
        ll id;
        string date, time;
        cin >> id >> date >> time;
        
        if(date.size() < 7){
            continue;
        }
        
        bool valid = true;
        for(int j=0; j<4; ++j){
            if(!isdigit(date[j])){
                valid = false;
                break;
            }
        }
        for(int j=5; j<7; ++j){
            if(!isdigit(date[j])){
                valid = false;
                break;
            }
        }
        if(!valid){
            continue;
        }
        
        int year = 0, month = 0;
        for(int j=0; j<4; ++j){
            year = year * 10 + (date[j] - '0');
        }
        for(int j=5; j<7; ++j){
            month = month * 10 + (date[j] - '0');
        }
        
        if(year == Y && month == M){
            u_id.insert(id);
        }
    }
    
    cout << "0 0 " << u_id.size() << "\n";
    
    return 0;
}
