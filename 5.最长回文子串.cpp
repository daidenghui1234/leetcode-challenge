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
        string ret="";
        int start=0,end=0;
        int len1=0,len2=0;
        int max=0;
        for(int i=0; i<s.length(); i++)
        {
            max = ret.length();
            start=end=i;
            len1=getlen(s,start,end);
            if(max < len1*2+1){
                ret = s.substr(start-len1,len1*2+1);
                max = ret.length();
            }
            if(i<s.length()-1&&s[i]==s[i+1]){
                start=i;
                end=i+1;
                len2=getlen(s,start,end);
                if(max < len2*2+2){
                    ret = s.substr(start-len2,len2*2+2);
                    max = ret.length();
                }
            }
        }


        return ret;
    }
private:
    int getlen(string s,int start,int end)
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