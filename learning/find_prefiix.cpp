#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<long long> cnt1(26,0),cnt2(26,0);
        long long ans = 0;
        int l = 0;
        }

    long long stepmux(int n){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans *= i;
        }
        return ans;
    }

};