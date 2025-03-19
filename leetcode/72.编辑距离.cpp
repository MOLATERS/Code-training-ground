#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
        int n = word1.length();
        int m = word2.length();
        for(int i = 0 ; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int left  = dp[i-1][j] + 1;
                int up = dp[i][j-1] + 1;
                int left_up = dp[i-1][j-1];
                if(word1[i-1]!= word2[j-1]) left_up += 1; 
                dp[i][j] = min(left,min(up,left_up));
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

