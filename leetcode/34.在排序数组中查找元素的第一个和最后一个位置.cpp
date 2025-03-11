#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l,r;
        vector<int> a = {-1,-1};
        l = 0;
        r = nums.size()-1;
        while(l <= r){
            int mid = (l + r) /2;
            if(nums[mid] == target){
                a[0] = mid;
                r = mid - 1;
            }
            if(nums[mid] > target) {
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        l= 0;
        r = nums.size()-1;
        while(l <= r){
            int mid = (l + r) /2;
            if(nums[mid] == target){
                a[1] = mid;
                l = mid + 1;
            }
            if(nums[mid] > target) {
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return a;
    }
};
// @lc code=end

