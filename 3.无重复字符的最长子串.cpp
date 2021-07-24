/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <string>
#include <unordered_map> // 无序的 建立慢 查找快
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start{0}, end{0}, length{0}, result{0};
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            // 当且仅当hash中存在end才会更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }

        return result;
    }
};
// @lc code=end

int main()
{
    Solution S;
    string str{"abcacdda"};
    int len = S.lengthOfLongestSubstring(str);
    cout << "str = " << str << " Max length is " << len << endl;
    system("pause");
}