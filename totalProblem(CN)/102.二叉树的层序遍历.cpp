/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// [102] 二叉树的层序遍历
// 23.24 % 79.49 %
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> tree;
        if (root == NULL)
            return tree;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int currentLevel = q.size();
            tree.emplace_back(vector<int>());
            for (int i = 0; i < currentLevel; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                // tree的最后一个元素（即一个列表）
                tree.back().emplace_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return tree;
    }
};
// @lc code=end
