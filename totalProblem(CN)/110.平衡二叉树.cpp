/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// 58.68 %  58.72 %
class Solution
{
public:
    int getDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int ldepth = getDepth(root->left);
        int rdepth = getDepth(root->right);
        return max(ldepth, rdepth) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        else
            return abs(getDepth(root->left) - getDepth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
