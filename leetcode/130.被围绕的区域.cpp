// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem130.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
// 任何边界上的 O 都不会被填充为 X。 我们可以想到，所有的不被包围的 O 都直接或间接与边界上的 O 相连。我们可以利用这个性质判断 O
// 从这个角度出发，那所有被遍历过的O都是没有被包围的，反之就都是被包围的。

class Solution
{
public:
    void dfs(vector<vector<char>> board, int x, int y)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0)
            return;
        if (board[0].size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();

        // 开始检查周围是否有O
        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        // 开始进行清算
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O'; // 不进行修改
                }
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end
