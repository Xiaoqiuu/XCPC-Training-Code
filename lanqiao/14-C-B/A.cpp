// #include <iostream>
#include <bits/stdc++.h>
// #include <vector>
using namespace std;
#define vi vector<int>
// class solution{
//     public:
        
//         }
// };

vi ans={0,0,0,0,0,0,0,0,0,0};
        vi solve(vi num){
            
            for(int i=0;i<num.size();i++){
                if(num[i]==0)ans[0]++;
                else if(num[i]==1)ans[1]++;
                else if(num[i]==2)ans[2]++;
                else if(num[i]==3)ans[3]++;
                else if(num[i]==4)ans[4]++;
                else if(num[i]==5)ans[5]++;
                else if(num[i]==6)ans[6]++;
                else if(num[i]==7)ans[7]++;
                else if(num[i]==8)ans[8]++;
                else if(num[i]==9)ans[9]++;
            }
            return ans;}

int main(){
    // solution s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi nums(41);
    std::cout << "Enter 41 numbers: ";
    for(int i=0;i<41;i++){
        std::cin >> nums[i];
    }
    vi ans = solve(nums);
    for(int i=0;i<10;i++){
        std::cout<< "The number of "<< i <<" is: " << ans[i] << "\n";
    }
    return 0;
}