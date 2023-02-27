/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// 位运算 + 二分查找
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int level = 0; // 遍历左节点，求出树的层数
        TreeNode *node = root;
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        // 节点的数量的下界和上界
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k)
    {
        // 判断k节点是否存在
        int bits = 1 << (level - 1); // 不看二进制最左边的第一位
        TreeNode *node = root;
        // 从左侧的第二位开始看，因为左半边的都会是0，右半边的都会是1
        // 所以可以这样不断地移动位数，实现二分
        while (node != nullptr && bits > 0)
        {
            if (!(bits & k))
                node = node->left;
            else
                node = node->right;
            bits >>= 1;
        }
        return node != nullptr;
    }
};

// @lc code=end
// 普通递归法 50.3% 90.50%
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};

// 完全二叉树的递归方法 50.3% 81.70%
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *leftnode = root->left;
        TreeNode *rightnode = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (leftnode)
        {
            leftnode = leftnode->left;
            leftDepth++;
        }
        while (rightnode)
        {
            rightnode = rightnode->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 二刷

// 位运算 + 二分查找
class Solution
{
public:
    bool exist(int k, TreeNode *node, int level)
    {
        for (int b = level - 1; node != nullptr && b >= 0; b--)
        {
            int cur = (1 << b) & k;
            node = cur == 0 ? node->left : node->right;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *tmp = root;
        int level = 0;
        while (tmp->left != nullptr)
        {
            level++;
            tmp = tmp->left;
        }
        int left = 1 << level, right = (1 << (level + 1)) - 1;
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if (exist(mid, root, level))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

// 另一种二分

// 位运算 + 二分查找
class Solution
{
public:
    bool exist(int k, TreeNode *node, int level)
    {
        for (int b = level - 1; node != nullptr && b >= 0; b--)
        {
            int cur = (1 << b) & k;
            node = cur == 0 ? node->left : node->right;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *tmp = root;
        int level = 0;
        while (tmp->left != nullptr)
        {
            level++;
            tmp = tmp->left;
        }
        int left = 1 << level, right = (1 << (level + 1)) - 1;
        while (left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if (exist(mid, root, level))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
};

/*
第一种方法中，每次计算mid时，用的是右移一位并加上left的方式，
这样得到的mid是偏向左边的，因此需要在判断节点是否存在时，将左右指针分别更新为mid和right。

第二种方法中，计算mid的方式是使用位运算和加法的方式，得到的mid是偏向右边的，
因此在判断节点是否存在时，需要将左右指针分别更新为left和mid -1。
