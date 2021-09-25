/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int value = symbolValues[s[i]];     // 获取当前字符对应数值
            if(i<n-1 && value < symbolValues[s[i+1]])   
            {        // 当当前值小于洗一个符号对应的值 这时候当前符号代表减
                ans -= value;
            }else{  // 当当前值大于洗一个符号对应的值 这时候当前符号代表加
                ans += value;
            }
        }
        return ans;
    }

private:
    // 符号对应值表
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};
// @lc code=end
