/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
//[230] 二叉搜索树中第K小的元素
// 69.49 %  25.89 %
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        inorder(root->left, v);
        v.emplace_back(root->val);
        inorder(root->right, v);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorderTree;
        inorder(root, inorderTree);
        return inorderTree[k - 1];
    }
};
// @lc code=end
