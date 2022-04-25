/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
// 24.91 % 19.63 %
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> Q;
        Q.push(root);
        int res = 0;
        while (!Q.empty())
        {
            int s = Q.size();
            while (s > 0)
            {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left != NULL)
                    Q.push(node->left);
                if (node->right != NULL)
                    Q.push(node->right);
                s--;
            }
            res++;
        }
        return res;
    }
};
// @lc code=end
//[104] 二叉树的最大深度
// 60.84 % 62.53 %
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return (max(maxDepth(root->left), maxDepth(root->right)) + 1);
    }
};
