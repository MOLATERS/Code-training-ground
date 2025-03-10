// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

#include <vector>
#include <string>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> answer; 
       findTheCorrect(n,answer,"",0,0);
       return answer;
    }

    void findTheCorrect(int n, vector<string> &answer, string temp, int open, int close)
    {
        if(answer.size()==n * 2){
            answer.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            findTheCorrect(n,answer,temp,open+1, close);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            findTheCorrect(n,answer,temp,open,close+1);
            temp.pop_back();
        }
    }

};
// @lc code=end

