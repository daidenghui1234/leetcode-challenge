/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 * 
 * Solution description:
 * 首先定义返回值时不能使用int类型，会导致处理精度不足引起错误
 * 重点在于：result = result * 10 + x % 10;
 */

#include <iostream>
using namespace std;



// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};
// @lc code=end
