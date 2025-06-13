class Solution {
public:
    int reverse(int x) {
        string s = to_sting(x);
        reverse(s);
        int ans = stoi(s);
        return ans;
    }
};