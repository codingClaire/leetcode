/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
// 23.11 % 79.35% 
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if(root == nullptr)
            return new TreeNode(val);
        TreeNode* pos = root;
        // 左右排查就行，因为一定存在一个不需要重建树的方法！！ 
        while(pos!=nullptr)
        {
            if(val < pos->val)
            {
                if(pos->left == nullptr)
                {
                    pos->left = new TreeNode(val);
                    break;
                }
                else 
                {
                    pos = pos->left;
                }
                    
            }
            else
            {
                if(pos->right == nullptr)
                {
                    pos->right = new TreeNode(val);
                    break;
                }
                else
                {
                    pos = pos->right;
                }
            }
        }
        return root;
    }
};
// @lc code=end
