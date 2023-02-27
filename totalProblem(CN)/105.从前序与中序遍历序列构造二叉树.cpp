/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
//[105] 从前序与中序遍历序列构造二叉树
// 96.62 % 53.05 %
class Solution
{
private:
    // 建立哈希表，存储中序遍历数组中每个元素对应的下标
    unordered_map<int, int> hashmp;

public:
    // 递归函数，构建二叉树
    TreeNode *build(vector<int> &preorder, vector<int> &inorder,
                    int pleft, int pright, int ileft, int iright)
    {
        // 如果前序遍历数组为空，返回空指针
        if (pleft >= pright)
            return NULL;
        // 取前序遍历数组的第一个元素作为根节点的值
        int root = preorder[pleft];
        // 创建当前节点
        TreeNode *tree = new TreeNode(root);
        // 获取当前节点在中序遍历数组中的下标
        int iroot = hashmp[root];
        // 计算左子树的节点数目
        int left_subtree = iroot - ileft;
        // 递归构建左子树
        tree->left = build(preorder, inorder, pleft + 1, pleft + left_subtree + 1, ileft, iroot);
        // 递归构建右子树
        tree->right = build(preorder, inorder, pleft + left_subtree + 1, pright, iroot + 1, iright);
        return tree;
    }

    // 主函数，用于调用递归函数构建二叉树
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 构建哈希表，存储中序遍历数组中每个元素对应的下标
        for (int i = 0; i < preorder.size(); i++)
            hashmp[inorder[i]] = i;

        // 调用递归函数构建二叉树
        TreeNode *tree = build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return tree;
    }
};
// @lc code=end
