/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <map>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::vector;

/*
 * Solution description:
 * 使用辅助空间map将原数组内容作为关键字key，下标作为值value
 * 首先将第一个数组第一个元素放入map -- 匹配需要两个以元素，所以第一个直接加入map
 * 进入循环，i从1开始。计算数target与组元素的差值difference_value，并作为关键字在map中查找
 * 如果未查找到将将原数组内容作为关键字key，下标作为值value传入map
 * 如果查找到返回差值difference_value对应map的值与i的值
 * 循环完成没有退出，证明未查找到满足条件的点，返回空
 */

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
