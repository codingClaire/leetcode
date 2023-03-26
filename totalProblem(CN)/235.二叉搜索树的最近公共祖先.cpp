/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
// 35.49% 88.56 %
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 二分式地查找即可
        TreeNode* cur = root;
        while(true)
        {
            if (cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else if (cur->val > p->val && cur->val > q->val)
                cur = cur->left;
            else
                break;
        }
        return cur;
    }
};
// @lc code=end

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        else if (p->val == root->val || q->val == root->val)
            return root;
        else if (p->val <= root->val && q->val > root->val)
            return root;
        else if (q->val <= root->val && p->val > root->val)
            return root;
        else if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};