/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
//
// 99.43 % 47.56%
class Solution
{
public:
    int res = INT_MIN;
    int getMaxGain(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        // 左右向下递归
        int leftGain = max(getMaxGain(node->left),0);
        int rightGain = max(getMaxGain(node->right),0);
        // 向上返回
        //聚集递归后左侧路径的最大值和右侧路径的最大值
        int priceNewPath = node->val + leftGain + rightGain;
        // 更新res
        res = max(res,priceNewPath);
        // 返回当前节点贡献最大的一条路径
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        getMaxGain(root);
        return res;
    }
};
// @lc code=end
