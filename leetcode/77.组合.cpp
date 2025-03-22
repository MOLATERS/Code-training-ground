// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> temp;
        vector<int> valid(k);
        backtrack(answer, temp, valid, k);
        return answer;
    }

    void backtrack(vector<vector<int>>& list, vector<int>& temp, vector<int>& valid, int k)
    {
        if(temp.size() == k)
        {
            list.push_back(temp);
            return;
        }
        for(int i = 0; i < valid.size(); i++)
        {
            if(valid[i] == 1) continue;
            valid[i] = 1;
            temp.push_back(i+1);
            backtrack(list, temp, valid, k);
            temp.pop_back();
        }
    }

};
// @lc code=end

