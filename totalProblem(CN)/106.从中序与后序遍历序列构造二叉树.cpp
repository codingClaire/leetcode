/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    // 记录后序遍历中当前根节点的位置
    int post_idx;
    // 建立哈希表，键为元素，值为下标，用于查询中序遍历中根节点的位置
    unordered_map<int, int> idx_map;

public:
    // helper函数用于递归构造二叉树
    TreeNode *helper(int in_left, int in_right, vector<int> &inorder, vector<int> &postorder)
    {
        // 如果中序遍历的左边界大于右边界，说明当前子树已经构造完成，返回空指针
        if (in_left > in_right)
        {
            return nullptr;
        }
        // 选择后序遍历的post_idx位置的元素作为当前子树的根节点
        int root_val = postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);
        // 根据根节点的值找到其在中序遍历中的位置
        int index = idx_map[root_val];
        // 下标减一，处理下一个根节点
        post_idx--;
        // 构造右子树，范围为当前根节点位置的右边到中序遍历的右边界
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树，范围为中序遍历的左边界到当前根节点位置的左边
        root->left = helper(in_left, index - 1, inorder, postorder);
        // 返回当前构造的根节点
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 从后序遍历的最后一个元素开始构造二叉树
        post_idx = (int)postorder.size() - 1;

        // 建立哈希表，记录中序遍历的元素和下标
        int idx = 0;
        for (auto &val : inorder)
        {
            idx_map[val] = idx++;
        }
        // 递归构造二叉树，并返回根节点
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end

