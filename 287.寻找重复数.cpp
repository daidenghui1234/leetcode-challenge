/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int elem : nums){
            if(map[elem]) return elem;
            map[elem] = true;
        }
        return -1;
    }
};
// @lc code=end

