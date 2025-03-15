// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        bool flag;
        vector<string> answer(numRows);
        int count = 0;
        int size = s.size();
        while(count < size)
        if(flag){
            for(int i =0; i< numRows;i++){
                answer[i] += s[count++];
            }
            flag -= flag;
        }
        else{
            for(int i = numRows -1; i > -1;i--){
                answer[i] += s[count++];
            }
            flag -= flag;
        }
        for(auto x: answer){
            cout<< x;
        }
    }
};
// @lc code=end

