/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// 81.82 % 74.16 %
//[98] 验证二叉搜索树
class Solution
{
public:
    bool helper(TreeNode *root, long left_value, long right_value)
    {
        if (root == NULL)
            return true;
        if (root->val <= left_value || root->val >= right_value)
        {
            return false;
        }
        bool left = helper(root->left, left_value, root->val);
        bool right = helper(root->right, root->val, right_value);
        return left && right;
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

//[5,4,6,null,null,3,7] 这个结果是false
//错误地解法
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        bool leftcur = false, rightcur = false;
        if (root->left == NULL || root->left->val < root->val)
            leftcur = true;
        if (root->right == NULL || root->right->val > root->val)
            rightcur = true;
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        return leftcur && rightcur && left && right;
    }
};