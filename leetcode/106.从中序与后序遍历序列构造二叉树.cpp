#include <vector>
#include <stack>

using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 需要指针和一个栈来维护
        stack<TreeNode*> stack;
        int index = inorder.size() -1;
        TreeNode* root = new TreeNode(postorder[index]);
        stack.push(root);

        for(int i = index - 1; i >= 0 ; i--) // 这是对后序序列的遍历
        {
            int p_num = postorder[i];
            TreeNode* node = stack.top();
            if(inorder[index] != node->val) { // inorder[index] represent the last right child of the current tree
                node->right = new TreeNode(p_num);
                stack.push(node->right);
            }
            else
            {
                while(!stack.empty() && inorder[index] == stack.top()->val) // find the closest ancestor, and become it's left tree
                {
                    node = stack.top();
                    stack.pop();
                    index --;
                }
                node->left = new TreeNode(p_num);
                stack.push(node->left);
            }
        }

        return root;
    }
};
// @lc code=end

