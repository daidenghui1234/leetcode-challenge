/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ret="";       // 返回值
        int start=0,end=0;  // 记录回文中心两边的字符位置
        int len=0;          // len记录回文两边匹配成功次数
        for(int i=0; i<s.length(); i++) // 循环判断 一每一个字符为中心
        {
            start=end=i;                // 考虑奇数情况
            len=getlen(s,start,end);    // 获取两边匹配长度
            if(ret.length() < len*2+1){ // 判断是否超过之前最大长度
                ret = s.substr(start-len,len*2+1);
            }
            if(i<s.length()-1&&s[i]==s[i+1]){   // 考虑偶数情况 当前位置与以一个位置字符相等
                start=i;
                end=i+1;
                len=getlen(s,start,end);        // 获取两边匹配长度
                if(ret.length() < len*2+2){     // 判断是否超过之前最大长度
                    ret = s.substr(start-len,len*2+2);
                }
            }
        }


        return ret;
    }
private:

    int getlen(string s,int start,int end)      //  获取两边匹配（相等）成功的次数
    {
        int len = 0;
        start--;
        end++;
        while(start>-1 && end<s.length() && s[start]==s[end])
        {
            len++;
            start--;
            end++;
        }

        return len;
    }
};
// @lc code=end