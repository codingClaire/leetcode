/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
public:
    void recur(TreeNode *node, int &val, int &depth, int &maxdepth)
    {
        TreeNode *tmp = node;

        if (tmp == nullptr)
            return;
        // update
        int cur_depth = depth + 1;
        if (tmp->left == nullptr && tmp->right == nullptr && cur_depth > maxdepth)
        {
            maxdepth = cur_depth;
            val = tmp->val;
        }
        recur(node->left, val, cur_depth, maxdepth);
        recur(node->right, val, cur_depth, maxdepth);
    }

    int findBottomLeftValue(TreeNode *root)
    {
        int val = 0, depth = 0, maxdepth = 0;
        recur(root, val, depth, maxdepth);
        return val;
    }
};
// @lc code=end

class Solution
{
public:
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode *root, int depth)
    {
        // 这里depth不需要加引用 因为是隐式递归调用
        if (root->left == NULL && root->right == NULL)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left)
        {
            traversal(root->left, depth + 1); // 隐藏着回溯
        }
        if (root->right)
        {
            traversal(root->right, depth + 1); // 隐藏着回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 0);
        return result;
    }
};