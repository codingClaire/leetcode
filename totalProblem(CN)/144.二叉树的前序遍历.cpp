/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// 40.82% 19.68%
class Solution
{
public:
    vector<int> res;
    void recur(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        res.emplace_back(root->val);
        recur(root->left, res);
        recur(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        recur(root, res);
        return res;
    }
};
// @lc code=end
// 100% 41.83% 复杂度O(N)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL)
            return res;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            // 先压入右子树，再压入左子树，保证左子树先遍历
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return res;
    }
};