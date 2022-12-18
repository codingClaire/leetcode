/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                level.emplace_back(cur->val);
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            res.emplace_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
}; // @lc code=end
// Wrong [1,2,3,4,null,null,5]
// 正确的是 [[4,5],[2,3],[1]] 而非 [4] [5] [2,3] [1]
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        res.push_back({root->val});
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr && cur->right != nullptr)
            {
                res.push_back({cur->left->val, cur->right->val});
                q.push(cur->left);
                q.push(cur->right);
            }
            else if (cur->left != nullptr)
            {
                res.push_back({cur->left->val});
                q.push(cur->left);
            }
            else if (cur->right != nullptr)
            {
                res.push_back({cur->right->val});
                q.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};