/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <algorithm>
#include <iostream>
#include <sstream> //要使用stringstream流应包含此头文件
#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        double iret = 0;
        if ((x >= INT_MAX) || (x <= INT_MIN))
        {
            return 0;
        }
        if (x < 0) // 记录正负
        {
            isNegative = true;
            x = -x;
        }
        while (x > 0)
        {
            iret = (iret + (x % 10)) * 10;
            x = x / 10;
        }
        iret = iret / 10;
        if (isNegative == true)
        {
            iret = iret * (-1);
        }
        if ((iret >= INT_MAX) || (iret <= INT_MIN))
        {
            return 0;
        }
        return iret;
    }

    bool isNegative = false;
};
// @lc code=end
