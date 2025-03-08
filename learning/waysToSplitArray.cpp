#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int split = 0;
        int answer = 0;
        int front_sum = 0;
        int back_sum = 0;
        for(int i=0;i<nums.size();i++){
            back_sum+=nums[i];
        }
        int temp;
        while(split < nums.size()-1){
            temp = nums[split++];
            front_sum+=temp;
            back_sum-=temp;
            if(front_sum >= back_sum && split < nums.size()) answer++;
        }
        return answer;
    }
};


int main(){
    std::vector<int> nums = {2,3,1,0};
    Solution solution;
    int actual = solution.waysToSplitArray(nums);
    cout << actual;
}