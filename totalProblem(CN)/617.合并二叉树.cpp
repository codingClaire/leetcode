/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        TreeNode *tmp = new TreeNode();
        if (root1 != nullptr && root2 != nullptr)
        {
            tmp->val = root1->val + root2->val;
            tmp->left = mergeTrees(root1->left, root2->left);
            tmp->right = mergeTrees(root1->right, root2->right);
        }
        else if (root1 == nullptr)
        {
            tmp->val = root2->val;
            tmp->left = mergeTrees(nullptr, root2->left);
            tmp->right = mergeTrees(nullptr, root2->right);
        }
        else if (root2 == nullptr)
        {
            tmp->val = root1->val;
            tmp->left = mergeTrees(root1->left, nullptr);
            tmp->right = mergeTrees(root1->right, nullptr);
        }
        return tmp;
    }
};
// @lc code=end
/*
在递归的时候，我们首先判断了t1和t2是否为nullptr，
如果其中有一个为nullptr，就直接返回另一个。
这种情况相当于将其中一颗子树直接接到了合并后的树上，
因为在合并的过程中，如果一个节点为空，则对应的子树为空，不影响整个树的结构。

*/
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr)
        {
            return t2;
        }
        if (t2 == nullptr)
        {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};
