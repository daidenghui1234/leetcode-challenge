/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

#include "MyHead.h"

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        int min = nums[0];

        int i = nums.size() - 1;
        for (; i > 0; i--)
        {
            if (min < nums[i])
            {
                break;
            }
            else if (min > nums[i])
            {
                min = nums[i];
            }
        }

        return min;
    }
};

// @lc code=end
