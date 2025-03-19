#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> f(grid.size(),vector<int>(grid[0].size()));
        f[0][0] = grid[0][0];
        for(int i = 1; i < f[0].size(); i++){
            f[0][i] = f[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < f.size(); i++){
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < f.size(); i++)
        {
            for(int j = 1; j < f[0].size(); j++){
                f[i][j] = min(f[i-1][j],f[i][j-1])+grid[i][j];
            }
        }
        return f[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

