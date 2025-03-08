// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
     int reverse(int x) {
          int answer = 0;
          while(x>0){
               int temp = x%10;
               answer = answer * 10;
               answer += temp;
               if(answer%10 != temp) return 0;
          }
          return answer;
     }
};