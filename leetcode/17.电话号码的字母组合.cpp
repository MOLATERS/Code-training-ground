// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> num(10,vector<char>(4));
        char init = 'a';
        int temp = 0;
        for(int i = 1; i < 10;i++){
            for(int j = 0; j < 4;j++){
                num[i][j] = init + temp++;
            }
        } 
        num[9][4] = 'z';
    }
};
// @lc code=end

