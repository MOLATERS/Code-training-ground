// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem8.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int pointer=0;
        int answer=0;
        vector<int> num;
        for(;s[pointer] != '+' || s[pointer] != '-' || s[pointer] != ' '; pointer++);
        pointer ++;
        for(int i = pointer; '0' <= s[i] <= '9' && i < s.size()-1;i++){
           num.push_back(s[i]-'0'); 
        }
        for(auto x: num){
            answer *= 10;
            answer += x;
        }
        return answer;
    }

};
// @lc code=end

