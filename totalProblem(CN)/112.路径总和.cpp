/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root  == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return  root->val == targetSum;
        return hasPathSum(root->left, targetSum- root->val) || hasPathSum(root->right, targetSum- root->val);
    }
};
// @lc code=end

class Solution 
{
public:
    bool recur(TreeNode* root, int leftSum)
    {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return leftSum == root->val;
        return recur(root->left,leftSum-root->val) || recur(root->right,leftSum-root->val);
    } 

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return recur(root, targetSum);
    }
};
