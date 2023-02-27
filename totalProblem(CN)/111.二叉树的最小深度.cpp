/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
//
// 41.79 % 61.90%
class Solution
{
public:
    int minDepth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        int depth = 0;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            depth += 1;
            while (s--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left == nullptr && node->right== nullptr)
                    return depth;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
// @lc code=end
