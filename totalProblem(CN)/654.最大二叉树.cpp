/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
// 38.01 % 83.4 %
class Solution
{
public:
    TreeNode *build(vector<int> &nums, int left, int right)
    {
        if(left>right)
            return nullptr;
        int maxv = nums[left];
        int maxindex = left;
        for (int i = left+1; i <= right; i++)
        {
            if (nums[i] > maxv)
            {
                maxv = nums[i];
                maxindex = i;
            }
        }
        TreeNode *root = new TreeNode(maxv);
        root->left = build(nums, left, maxindex - 1);
        root->right = build(nums, maxindex + 1, right);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if(nums.size() == 0)
            return nullptr;
        return build(nums, 0, int(nums.size()) - 1);
    }
};
// @lc code=end
