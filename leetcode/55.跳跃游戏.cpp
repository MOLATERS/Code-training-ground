#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        for(int i = 0; i< n ; i++)
        {
            if( i <= right )
            {
                right = max(right, i+nums[i]);
                if(right >= n-1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// @lc code=end

