// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem99.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// 现在进行的更换操作都是在序列中有两个需要进行交换的结点，这两个结点不一定靠近，但是一定是有两处可能的异常位置上

class Solution {
public:
    vector<int> nums;
    int count = 2;
    void recoverTree(TreeNode* root) {
        inOrder(root);
        pair<int,int> recover = findIndex(root);
        changePair(recover, root);
    }

    void changePair(pair<int,int> pair,TreeNode* root){
        if(root != nullptr){
            if(root->val == pair.first || root -> val == pair.second ){
                root-> val = root -> val == pair.first ? pair.second : pair.first;
                if(--count == 0) return;
            }
        }
        changePair(pair,root->right);
        changePair(pair,root->left);
    }

    pair<int,int> findIndex(TreeNode* root){
        int n = nums.size();
        int index_1 = -1, index_2= -1;
        for(int i = 0; i< n-1;i++){
           if(nums[i] > nums[i+1]) 
           {
                index_2 = i+1;
                if(index_1 == -1){
                    index_1 = i;
                }
                else{
                    break;
                }
           }
        }
        return {nums[index_1], nums[index_2]};
    }

    // 中序遍历获得当前的序列
    void inOrder(TreeNode* root){
        if(root == nullptr)return;
        inOrder(root->left);
        nums.push_back(root->val);
        inOrder(root->right);
    }

};
// @lc code=end

