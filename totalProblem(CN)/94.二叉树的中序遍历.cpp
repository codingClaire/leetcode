/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
// [94] 二叉树的中序遍历
// 100 % 98.76 %
class Solution {
public:
    void inorder(TreeNode* tmp, vector<int>& res)
    {
        if(tmp == NULL)
            return;
        inorder(tmp->left,res);
        res.emplace_back(tmp->val);
        inorder(tmp->right,res);
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
// @lc code=end

