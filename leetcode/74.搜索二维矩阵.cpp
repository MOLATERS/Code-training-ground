#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = 0;
        int m = 0;
        queue<pair<int,int>> q;
        while(!q.empty() && matrix[q.front().first][q.front().second] < target){
            pair p = q.front();
            if(matrix[p.first][p.second] < target) q.push({n,m});
        }

    }
};
// @lc code=end

