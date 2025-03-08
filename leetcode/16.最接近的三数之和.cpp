// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem16.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int i = 0;
       int size = nums.size()-1;
       int answer = INT_MAX;
       while(i < size-2 && nums[i] < target){
            int rest = target - nums[i];
            int min = findmin(rest, i, size, nums);
            answer = nums[i] + min; 
            i++;
       }
       return answer;
    }
    int findmin(int rest, int index, int size, const vector<int> nums)
    {
        int head, tail;
        head = index+1;
        tail = size -1;
        int min = nums[head] + nums[tail];
        while(head < tail){
            min = absolute(nums[head] + nums[tail], rest) > absolute(min,rest) ? min: nums[head] + nums[tail];
            if(nums[head] + nums[tail] < rest){
                head ++;
            }
            if(nums[head] + nums[tail] >= rest){
                tail --;
            }
        }
        return min;
    }
    int absolute(int a,int b){
        return a>b? a-b:b-a;
    }
};
// @lc code=end

