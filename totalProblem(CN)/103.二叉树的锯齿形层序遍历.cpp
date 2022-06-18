/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
//[103] 二叉树的锯齿形层序遍历
// 58.16 %  44.14 %
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        deque<TreeNode *> q;
        q.emplace_back(root);
        bool reverse = false;
        while(!q.empty())
        {
            int curSize = q.size();
            vector<int> level;
            for(int i=0;i<curSize;i++)
            {   
                if(reverse == true) // reverse 
                {
                    TreeNode *node = q.front();
                    q.pop_front();
                    level.emplace_back(node->val);
                    if (node->right != NULL)
                        q.emplace_back(node->right);
                    if (node->left != NULL)
                        q.emplace_back(node->left);
                    
                }
                else{ // normal 
                    TreeNode *node = q.back();
                    q.pop_back();
                    level.emplace_back(node->val);
                    if (node->left != NULL)
                        q.emplace_front(node->left);
                    if (node->right != NULL)
                        q.emplace_front(node->right);
                     
                }
            }
            res.emplace_back(level);
            reverse = !reverse;
        }
        return res;
    }
};
// @lc code=end
//[103] 二叉树的锯齿形层序遍历
// 100 % 33.27 %
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty())
        {
            int curSize = q.size();
            deque<int> level;
            for (int i = 0; i < curSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (reverse == false)
                    level.push_back(node->val);
                else
                    level.push_front(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            res.emplace_back(vector<int>{level.begin(), level.end()});
            reverse = !reverse;
        }
        return res;
    }
};