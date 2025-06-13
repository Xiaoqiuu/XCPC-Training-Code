#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> newVector = nums1 + nums2;
        int olen = nums1.size() + nums2.size();
        vector<int> newVector(olen);
        for (int i = 0; i < nums1.size(); i++) newVector[i] = nums1[i];
        for (int i = 0; i < nums2.size(); i++) newVector[i+nums1.size()] = nums2[i];
        int mid = 0, int len =  newVector.size();
        sort(newVector.begin(), newVector.end());
        if (len % 2 == 0) return (double)(newVector[mid] + newVector[mid-1])/2;
        else return (double)newVector[mid];
    }
};