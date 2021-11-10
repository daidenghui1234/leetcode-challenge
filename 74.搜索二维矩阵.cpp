/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        if(!matrix.empty() && rows > 0 && cols > 0){
            int row = 0;
            int col = cols - 1;
            while(row < rows && col >= 0){
                if(matrix[row][col] == target){
                    return true;
                }
                else if(matrix[row][col] > target){
                    --col;
                }
                else{
                    ++row;
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{-1},{-1}};
    cout << Solution().searchMatrix(v, 9) << endl;

    system("pause");
    return 0;
}