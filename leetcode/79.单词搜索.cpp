// @before-stub-for-debug-begin
// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

#include <vector>
#include <string>

using namespace std;
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (board.empty() || word.empty()) return false;
        char head = word[0];
        vector<vector<int>> valid(m, vector<int>(n, 0));
        vector<pair<int, int>> p;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == head) {
                    p.push_back({i, j});
                }
            }
        }
        for (auto x : p) {
            valid[x.first][x.second] = 1;
            if (findWord(x, valid, board, word.substr(1))) return true;
            valid[x.first][x.second] = 0;
        }
        return false;
    }

    bool findWord(pair<int, int> start, vector<vector<int>>& valid, vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        vector<pair<int, int>> c;
        int m = board.size();
        int n = board[0].size();
        if (start.first < m - 1 && valid[start.first + 1][start.second] == 0 && board[start.first + 1][start.second] == word[0]) {
            c.push_back({start.first + 1, start.second});
        }
        if (start.first > 0 && valid[start.first - 1][start.second] == 0 && board[start.first - 1][start.second] == word[0]) {
            c.push_back({start.first - 1, start.second});
        }
        if (start.second > 0 && valid[start.first][start.second - 1] == 0 && board[start.first][start.second - 1] == word[0]) {
            c.push_back({start.first, start.second - 1});
        }
        if (start.second < n - 1 && valid[start.first][start.second + 1] == 0 && board[start.first][start.second + 1] == word[0]) {
            c.push_back({start.first, start.second + 1});
        }
        for (auto x : c) {
            valid[x.first][x.second] = 1;
            if (findWord(x, valid, board, word.substr(1))) {
                return true;
            }
            valid[x.first][x.second] = 0;
        }
        return false;
    }
};
// @lc code=end

// @lc code=end

