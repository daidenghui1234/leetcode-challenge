/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        float result;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int m=nums1.size();
        if(m%2){
            result=nums1[m/2];
        }else{
            result=(float(nums1[m/2-1])+float(nums1[m/2]))/2;
        }
    return result;
    }
};
// @lc code=end
