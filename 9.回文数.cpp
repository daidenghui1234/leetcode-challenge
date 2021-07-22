/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 * 
 * Solution description:
 * 负数和后面带有0的数都不是回文数。提前排除
 * 取传入数字的一半求反 与剩下一半比较
 * 循环条件剩下一半小于求反一般时退出
 * 奇数与偶数位时处理 :
 * 偶数时求反等于剩余直接判断
 * 奇数时求反比剩余多一位，求反的个位--原数字中间一位 求反/10 ==剩余
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x / 10 != 0 && x % 10 == 0))
        {
            return false;
        }
        int reverse_end = 0;
        while (x > reverse_end)
        {
            reverse_end = reverse_end * 10 + x % 10;
            x = x / 10;
        }
        return (x == reverse_end) || (x == reverse_end / 10);
    }
};
// @lc code=end
