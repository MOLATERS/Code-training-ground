#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int m, n;
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1')
        {
            return;
        }
        grid[x][y] = '0'; // 被水淹没
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        m = grid.size();
        n = grid[0].size();
        if (m == 0 || n == 0)
            return 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end
