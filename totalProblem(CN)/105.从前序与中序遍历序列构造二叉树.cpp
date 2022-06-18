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
    unordered_map<int, int> hashmp;

public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, 
                    int pleft, int pright, int ileft, int iright)
    {
        if (pleft >= pright)
            return NULL;
        int root = preorder[pleft];
        TreeNode *tree = new TreeNode(root);
        int iroot = hashmp[root];
        int left_subtree = iroot - ileft;
        tree->left = build(preorder, inorder, pleft + 1, pleft + left_subtree + 1, ileft, iroot);
        tree->right = build(preorder, inorder, pleft + left_subtree + 1, pright, iroot + 1, iright);
        return tree;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < preorder.size(); i++)
            hashmp[inorder[i]] = i;

        TreeNode *tree = build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return tree;
    }
};
// @lc code=end
