/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//[101] 对称二叉树
// 76.03 % 23.3 %
class Solution
{
public:
    bool recursive(TreeNode *left, TreeNode *right)
    {
        if(left == nullptr && right!=nullptr)
            return false;
        if (right== nullptr && left!= nullptr)
            return false;
        if (right == nullptr && left== nullptr)
            return true;
        if (left->val != right->val)
            return false;
        return recursive(left->left, right->right) &&  recursive(left->right, right->left);  
    }

    bool isSymmetric(TreeNode *root)
    {
        return recursive(root->left, root->right);
    }
};
// @lc code=end
// 72.77 % 70.91 %
class Solution
{
public:
    bool helper(TreeNode *leftnode, TreeNode *rightnode)
    {
        if (leftnode == NULL && rightnode == NULL)
            return true;
        if (leftnode == NULL && rightnode != NULL)
            return false;
        if (rightnode == NULL && leftnode != NULL)
            return false;
        bool cur = false;
        if (leftnode->val == rightnode->val)
            cur = true;
        bool left = helper(leftnode->left, rightnode->right);
        bool right = helper(leftnode->right, rightnode->left);
        return cur && left && right;
    }

    bool isSymmetric(TreeNode *root)
    {
        return helper(root->left, root->right);
    }
};