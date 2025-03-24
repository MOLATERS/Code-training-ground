// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> answer;
    vector<string> restoreIpAddresses(string s) {
        checkValid(s, 0, 0);
        return answer;
    }

    bool isValidSegment(const string& segment) {
        if (segment.size() > 3 || segment.size() == 0) return false;
        if (segment.size() > 1 && segment[0] == '0') return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }

    void checkValid(string s, int start, int count) {
        if (count == 3) {
            string segment = s.substr(start);
            if (isValidSegment(segment)) {
                answer.push_back(s);
            }
            return;
        }

        for (int i = 1; i <= 3 && start + i < s.size(); i++) {
            string segment = s.substr(start, i);
            if (isValidSegment(segment)) {
                string newS = s;
                newS.insert(start + i, ".");
                checkValid(newS, start + i + 1, count + 1);
            }
        }
    }
};    
// @lc code=end

