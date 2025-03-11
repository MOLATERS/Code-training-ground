#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //从后向前 找一对相邻升序元素 nums[i]< nums[j]
        int i=n-2,j=n-1;
        while(i>=0 && nums[i]>=nums[j]){
            i--;
            j--;
        }
        if(i>=0){//找到了相邻升序元素对，说明nums不是降序的那个
            //nums[i]就是“小数”
            //需要找“大数”来和“小数”交换：
            //在[j,end) 从后向前 查找第一个满足nums[k]>nums[i]的k,nums[k]作为"大数"
            int k=n-1;
            while(nums[k]<=nums[i]){
                k--;
            }
            swap(nums[i],nums[k]);
        }
        //逆置 [j,end)，使其升序
        int l=j,r=n-1;
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};

