/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "MyHead.h"

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int flag = 0;
        for (int elem : nums)
        {
            flag ^= elem;
        }

        return flag;
    }
};
// @lc code=end

int singleNumber(vector<int> &nums)
{
    unordered_set<int> hashSet_int;
    for (int elem : nums)
    {
        if (hashSet_int.count(elem) <= 0)
        {
            hashSet_int.insert(elem);
        }
        else
        {
            hashSet_int.erase(elem);
        }
    }
    if (hashSet_int.empty())
        return -1;
    else
    {
        return *(hashSet_int.begin());
    }
    string a;
}

char firstUniqChar(string s)
{
    unordered_multiset<char> hashChar;
    list<char> listc;
    for (char elem : s)
    {
        hashChar.insert(elem);
        if (hashChar.count(elem) > 2)
            continue;
        auto temp = find(listc.begin(), listc.end(), elem);
        if (temp == listc.end())
        {
            listc.push_back(elem);
        }
        else
        {
            listc.erase(temp);
        }
    }

    if (listc.empty())
        return ' ';
    else
        return *(listc.begin());
}