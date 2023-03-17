/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//100% 61.60% 
class Solution
{
public:
    vector<int> res;
    void recur(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        recur(root->left, res);
        recur(root->right, res);
        res.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        recur(root, res);
        return res;
    }
};
// @lc code=end


class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);   
        }
        // 以上得到中右左的遍历
        reverse(result.begin(), result.end());
        // reverse就可以得到左右中
        return res;
    }
};
