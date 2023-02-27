/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int getDepth(TreeNode *node, int depth)
    {
        if (node == nullptr)
            return depth;
        return max(getDepth(node->left, depth + 1), getDepth(node->right, depth + 1));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return abs(getDepth(root->left, 0) - getDepth(root->right, 0)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};