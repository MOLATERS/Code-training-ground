#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0;
        int tail = height.size()-1;
        int answer = 0;
        while(head < tail){
            int temp = min(height[head],height[tail])*(tail-head);
            if(height[head] <= height[tail]) head ++;
            else tail --;
            answer = temp > answer ? temp:answer;
        }
        return answer;
    }
};
// @lc code=end
