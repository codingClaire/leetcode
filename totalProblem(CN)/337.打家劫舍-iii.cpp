/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
// 61.09 % 53.87 %
class Solution
{
public:
    unordered_map<TreeNode*, int> f,g;
    void dfs(TreeNode* node)
    {
        if(!node)
            return;
        dfs(node->left);
        dfs(node->right);
        // 哈希 调用的时候会初始化为0
        f[node] = node->val + g[node->left] + g[node->right]; //f是选当前节点，g是不选的
        // 后序遍历 左孩子选或者不选 右孩子选或不选
        g[node] = max(f[node->left], g[node->left])+max(f[node->right], g[node->right]);
    }
    int rob(TreeNode *root)
    {
        dfs(root);
        return max(f[root], g[root]);
    }
};
// @lc code=end
