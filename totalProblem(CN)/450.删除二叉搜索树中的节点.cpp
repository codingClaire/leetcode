/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        bool lflag = false;
        while (cur != nullptr)
        {
            if (key < cur->val)
            {
                prev = cur;
                cur = cur->left;
                lflag = true;
            }
            else if (key > cur->val)
            {
                prev = cur;
                cur = cur->right;
                lflag = false;
            }
            else
            {
                // 左边为空，直接copy右子树
                if (cur->left == nullptr)
                {
                    if (prev == nullptr)
                        root = cur->right;
                    // 挂到prev上
                    else if (lflag == false)
                        prev->right = cur->right;
                    else
                        prev->left = cur->right;
                }
            }
            else
            {
                // 左边不为空
                TreeNode *replace = cur->left;
                // 找到左子树最右侧的节点（即最大的节点）
                while (replace->right != nullptr)
                    replace = replace->right;
                // 然后把右子树挂上去
                replace->right = cur->right;
                // prev是null的情况，即删除的是根节点的情况
                if (prev == nullptr)
                    root = cur->left;
                // 挂到prev上
                else if (lflag == false)
                    prev->right = cur->left;
                else
                    prev->left = cur->left;
            }
            break;
        }
    }
    return root;
};
// @lc code=end


// 出错的版本
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *cur = root;
        TreeNode *dummy = new TreeNode(-100000);
        TreeNode *prev = dummy;
        dummy->right = root;
        bool lflag = false;
        while (cur != nullptr)
        {
            if (key < cur->val)
            {
                prev = cur;
                cur = cur->left;
                lflag = true;
            }
            else if (key > cur->val)
            {
                prev = cur;
                cur = cur->right;
                lflag = false;
            }
            else
            {
                cout << prev->val << " ";
                if (lflag == false)
                    prev->right = cur->left;
                else
                    prev->left = cur->left;
                // 需要下移的情况
                if (prev->right != nullptr && lflag == false)
                    prev = prev->right;
                else if (prev->left != nullptr && lflag == true)
                    prev = prev->left;
                while (prev != nullptr && prev->right != nullptr)
                    prev = prev->right;
                if (prev != nullptr)
                    prev->right = cur->right;
                break;
            }
        }
        return dummy->right;
    }
};

