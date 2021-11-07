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
        vector<int> sum = nums1;
        double ret;
        for (int i = 0; i < nums2.size(); i++)
        {
            sum.push_back(nums2[i]);
        }
        sort(sum.begin(), sum.end());
        int endlen = sum.size();
        if(endlen%2==0){
            ret = (sum[endlen/2]+sum[endlen/2+1])/2.0;
        }
        ret = sum[endlen/2];
        return ret;
    }
};
// @lc code=end
