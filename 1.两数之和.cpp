/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <map>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::map;
using std::vector;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> map_temp;
        int difference_value = 0;
        map_temp[nums[0]] = 0; // 将第一个元素直接插入map
        for (int i = 1; i < nums.size(); i++)
        {
            difference_value = target - nums[i];
            if (map_temp.count(difference_value) < 1) // map内没有
            {
                map_temp[nums[i]] = i; // 将第一个元素直接插入map
            }
            else
            { // map内存中
                return {map_temp[difference_value], i};
            }
        }
        return {};
    }
};
// @lc code=end
