// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        int j;
        vector<vector<int>> answer;
        if(size == 0){
            answer.push_back(newInterval);
        }
        for(int i = 0 ;i < size; i++)
        {
            if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0])
            {
                j = i;
                while(intervals[j+1][0] <= newInterval[1]) j++;
                int right = intervals[j][1] > newInterval[1] ? intervals[j][1] : newInterval[1];
                int left = intervals[i][0];
                answer.push_back({left,right});
                break;
            }
            else
            {
                answer.push_back(intervals[i]);
            }
        }
        for(int i = j+1; i<size;i++){
            answer.push_back(intervals[i]);
        }
        return answer;
    }
};
// @lc code=end

