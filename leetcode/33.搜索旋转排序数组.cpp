// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 1;
        while(nums.size() > 1 && i < nums.size() &&nums [i-1] < nums[i] ) i++;
        int offset = nums.size()-i; // 表示有没有进行移动和移动的步数
        int head = 0;
        int tail = nums.size()-1;
        while(head <= tail){
            int middle = (head + tail)/2;
            int target_index = (middle + offset)%nums.size();
            if(head == tail && target == nums[target_index]) return target_index;
            if(target < nums[target_index]) 
            {
                tail = middle - 1;
            }
            if(target > nums[target_index]) 
            {
                head = middle + 1;
            }
            if(target == nums[target_index]) 
            {
                return target_index;
            }
        }    
        return -1;
    }
};
// @lc code=end

