#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string replaceSpace(string s)
{
    size_t found = s.find(" ");
    while (s.find(" ") != string::npos)
    {
        s.replace(found, 1, "%20");
        found = s.find(" ");
    }
    return s;
}

string reverseLeftWords(string s, int n)
{
    char tempc;
    int len = s.length() - 1;
    for (int i = 0; i < n; i++)
    {
        tempc = s[0];
        for (int j = 0; j < len; j++)
        {
            s[j] = s[j + 1];
        }
        s[len] = tempc;
    }

    return s;
}

int search(vector<int> &nums, int target)
{
    return count(nums.begin(), nums.end(), target);
}

int missingNumber(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        
        int loss_number = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)
            {
                loss_number = i;
                break;
            }
        }
        return loss_number;
    }

#endif // __TEST_H__