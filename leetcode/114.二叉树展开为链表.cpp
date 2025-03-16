// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    queue<TreeNode *> q;

    void forder(TreeNode* root){
        if(root == nullptr) return;
        q.push(root);
        forder(root->right);
        forder(root->left);
    }

    void flatten(TreeNode* root) {
        forder(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop() ;
            temp->left = nullptr;
            temp->right = q.front();
        }
    }
};
// @lc code=end

