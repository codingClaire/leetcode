/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
class Solution
{
public:
    void recur(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
            return;
        recur(root->left, inorder);
        inorder.emplace_back(root->val);
        recur(root->right, inorder);
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> inorder;
        recur(root, inorder);
        int minv = INT_MAX;
        for (int i = 0; i < inorder.size() - 1; i++)
        {
            minv = min(minv, abs(inorder[i] - inorder[i + 1]));
        }
        return minv;
    }
};
// @lc code=end
// 这是有问题的： 并不是一定在相邻的节点！！
//  [236,104,701,null,227,null,911]
class Solution
{
public:
    void helper(TreeNode *root, int &minv)
    {
        if (minv == 0 || root == nullptr)
            return;
        if (root->left != nullptr)
        {
            minv = min(minv, abs(root->left->val - root->val));
        }
        if (root->right != nullptr)
        {
            minv = min(minv, abs(root->right->val - root->val));
        }
        helper(root->left, minv);
        helper(root->right, minv);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int minv = INT_MAX;
        helper(root, minv);
        return minv;
    }
};