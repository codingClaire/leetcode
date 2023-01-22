/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
// 69.89 % 56.85 %
class Solution 
{
public:
    void DFS(TreeNode* node, vector<string>& res,string& tmp)
    {
        if(node == nullptr)
            return;
        string tmp_new = tmp + to_string(node->val);
        if(node->left != nullptr || node->right != nullptr)
            tmp_new += "->";
        if (node->left == nullptr && node->right == nullptr)
        {
            res.emplace_back(tmp_new);
            return;
        }
        DFS(node->left, res, tmp_new);
        DFS(node->right, res, tmp_new);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string tmp = "";
        DFS(root, res, tmp);
        return res;
    }
};
// @lc code=end

