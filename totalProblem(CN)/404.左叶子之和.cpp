/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
// 100% 68.33%
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *tmp = root;
        // root->right 的递归调用
        int val = sumOfLeftLeaves(tmp->right);
        tmp = tmp->left;
        // 判断是左子树
        val += (tmp != nullptr && tmp->left == nullptr && tmp->right == nullptr) ? tmp->val : 0;
        // tmp的递归调用
        val += sumOfLeftLeaves(tmp);
        return val;
    }
};
// @lc code=end
