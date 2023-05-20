/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
// 把二叉搜索树修建到(low,high)区间
// 84.99 % 39.94 %
class Solution 
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        // 边界条件
        if(root == nullptr)
            return nullptr;
        if(root->val < low)
        {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high)
        {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        // 递归
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right,low, high);
        return root;
    }
};
// @lc code=end

