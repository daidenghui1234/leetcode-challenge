/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 
 * Solution description:
 * 获取传入的区间数量 小于等于1直接返回
 * 对传入的区间进行排序
 * 建立新容器并将一个区间加入容器vec
 * 下标从1开始比对 新加入区间与下一个区间重合
 * 如果重合 修改新容器vec右区间的值 区间不重合直接将其加入新容器vec（此时j++）
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n <= 1)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> vec;

        vec.push_back(intervals[0]); // 先将第一个区间加入

        // i从1开始控制原数组 j从零开始控制新数组
        for (int i = 1, j = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= vec[j][1])                // 新加入区间与下一个区间重合
                vec[j][1] = max(vec[j][1], intervals[i][1]); // 修改右区间的值
            else
            {
                vec.push_back(intervals[i]); // 区间不重合直接加入
                j++;
            }
        }
        return vec;
    }
};
// @lc code=end
