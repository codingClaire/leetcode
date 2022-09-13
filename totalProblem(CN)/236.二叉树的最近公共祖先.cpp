/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法二：存储父节点
// 5.67 % 5.32 %
class Solution
{
public:
    TreeNode *ans;
    unordered_map<int, TreeNode *> fa;
    unordered_map<int, bool> vis;
    void DFS(TreeNode *root)
    {
        if (root->left != nullptr)
        {
            fa[root->left->val] = root;
            DFS(root->left);
        }
        if (root->right != nullptr)
        {
            fa[root->right->val] = root;
            DFS(root->right);
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        fa[root->val] = nullptr;
        DFS(root);
        while (p != nullptr)
        {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr)
        {
            if (vis[q->val])
                return q;
            q = fa[q->val];
        }
        return nullptr;
    }
}; // @lc code=end
// 方法一： 递归
// 67.12% 25.63 %
class Solution
{
public:
    TreeNode *ans;
    bool DFS(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return false;
        bool lson = DFS(root->left, p, q);
        bool rson = DFS(root->right, p, q);
        if (lson && rson)
            ans = root;
        if ((root->val == p->val || root->val == q->val) && (lson || rson))
            ans = root;
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        DFS(root, p, q);
        return ans;
    }
};