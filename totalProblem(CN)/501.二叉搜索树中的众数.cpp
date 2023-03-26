/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

// 92.10 % 60.85 %
class Solution
{
public:
    vector<int> modes;
    int curval = -1;
    int curcount = 0;
    int maxcount = 0;
    void update(int val)
    {
        if (val != curval)
        {
            curval = val;
            curcount = 0;
        }
        curcount++;
        //每轮都要判断！！！！ 
        if (curcount == maxcount)
            modes.emplace_back(curval);
        else if (curcount > maxcount)
        {
            maxcount = curcount;
            modes = vector<int>{curval};
        }
    }
    void DFS(TreeNode *root)
    {
        if (!root)
            return;
        DFS(root->left);
        update(root->val);
        DFS(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        DFS(root);
        return modes;
    }
};
// @lc code=end

// 这个的问题就是最后一个没办法处理，
// 所以判断curcount和maxcount需要每一轮都判断
class Solution
{
public:
    vector<int> modes;
    int curval = -1;
    int curcount = 0;
    int maxcount = 0;
    void update(int val)
    {
        if (val != curval)
        {
            curval = val;
            if (curcount == maxcount)
                modes.emplace_back(curval);
            else if (curcount > maxcount)
            {
                maxcount = curcount;
                modes = vector<int>{curval};
            }
            curcount = 0;
        }
        curcount++;
    }
    void DFS(TreeNode *root)
    {
        if (!root)
            return;
        DFS(root->left);
        update(root->val);
        DFS(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        DFS(root);
        return modes;
    }
};
//////////////////// 上面这个是错的 /////////////////////////////
// Morris 中序遍历 71.60% 61.95 %

class Solution
{
public:
    vector<int> modes;
    int curval = -1;
    int curcount = 0;
    int maxcount = 0;
    void update(int val)
    {
        if (val != curval)
        {
            curval = val;
            curcount = 0;
        }
        curcount++;
        if (curcount == maxcount)
            modes.emplace_back(curval);
        else if (curcount > maxcount)
        {
            maxcount = curcount;
            modes = vector<int>{curval};
        }
    }

    vector<int> findMode(TreeNode *root)
    {
        // 定义两个指针，cur 指向当前节点，pre 指向 cur 的前驱节点
        TreeNode *cur = root, *pre = nullptr; 
        while (cur)
        { // 当 cur 不为空时
            if (!cur->left)
            { // 如果 cur 没有左子树，更新 base 和 count，并把 cur 指向右子树
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left; 
            // 否则，把 cur 的前驱节点设置为其左子树的最右节点
            while (pre->right && pre->right != cur)
            {
                pre = pre->right;
            }
            if (!pre->right)
            {   // 如果前驱节点的右指针为空，说明第一次遍历到该节点，
                //把前驱节点的右指针指向 cur，cur 指向左子树
                pre->right = cur;
                cur = cur->left;
            }
            else
            {   // 如果前驱节点的右指针不为空，说明已经遍历过该节点，
                //更新 base 和 count，把前驱节点的右指针置为空，cur 指向右子树
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return modes;
    }
};
// [6,3,7,2,4,null,8,1,null,null,5,null,9]