// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 0;
        int l_t_r = 0;
        int r_t_l = n-1;
        int u_t_d = 0;
        int d_t_u = n-1;
        vector<vector<int>> answer(n, vector<int>(n));
        while(count <= n*n){
            for(int i = l_t_r; i <= r_t_l;i++)
            {
                answer[u_t_d][i] = count++;
            }
            u_t_d++;
            for(int i = u_t_d; i <= d_t_u; i++)
            {
                answer[i][r_t_l]= count++;
            }
            r_t_l++;
            for(int i = r_t_l; i >= l_t_r; i--)
            {
                answer[d_t_u][i] = count++;
            }
            d_t_u++;
            for(int i = d_t_u; i <= u_t_d;i++)
            {
                answer[i][l_t_r];
            }
            l_t_r++;
        }
        return answer;
    }
};
// @lc code=end

