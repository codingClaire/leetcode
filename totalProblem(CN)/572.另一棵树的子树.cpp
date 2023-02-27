/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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

// @lc code=end

// 法一：递归（深度优先搜索）方法 72.14 % 69.86 %
class Solution
{
public:
    bool recur(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        return root->val == subRoot->val && recur(root->left, subRoot->left) && recur(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        return recur(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// 法二：序列化 + KMP
class Solution
{
public:
    vector<int> sOrder, tOrder;
    int maxElement, lNull, rNull;

    void getMaxElement(TreeNode *o)
    {
        if (!o)
        {
            return;
        }
        maxElement = max(maxElement, o->val);
        getMaxElement(o->left);
        getMaxElement(o->right);
    }

    void getDfsOrder(TreeNode *o, vector<int> &tar)
    {
        if (!o)
        {
            return;
        }
        tar.push_back(o->val);
        if (o->left)
        {
            getDfsOrder(o->left, tar);
        }
        else
        {
            tar.push_back(lNull);
        }
        if (o->right)
        {
            getDfsOrder(o->right, tar);
        }
        else
        {
            tar.push_back(rNull);
        }
    }

    bool kmp()
    {
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector<int> fail(tOrder.size(), -1);
        for (int i = 1, j = -1; i < tLen; ++i)
        {
            while (j != -1 && tOrder[i] != tOrder[j + 1])
            {
                j = fail[j];
            }
            if (tOrder[i] == tOrder[j + 1])
            {
                ++j;
            }
            fail[i] = j;
        }
        for (int i = 0, j = -1; i < sLen; ++i)
        {
            while (j != -1 && sOrder[i] != tOrder[j + 1])
            {
                j = fail[j];
            }
            if (sOrder[i] == tOrder[j + 1])
            {
                ++j;
            }
            if (j == tLen - 1)
            {
                return true;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        maxElement = INT_MIN;
        getMaxElement(s);
        getMaxElement(t);
        lNull = maxElement + 1;
        rNull = maxElement + 2;

        getDfsOrder(s, sOrder);
        getDfsOrder(t, tOrder);

        return kmp();
    }
};

// 树哈希

class Solution
{
public:
    static constexpr int MAX_N = 1000 + 5;   // 最大的节点数
    static constexpr int MOD = int(1E9) + 7; // 取模数

    bool vis[MAX_N];   // 标记是否为合数
    int p[MAX_N], tot; // 存放质数和质数的数量

    void getPrime()
    { // 获取质数表
        vis[0] = vis[1] = 1;
        tot = 0;
        for (int i = 2; i < MAX_N; ++i)
        {
            if (!vis[i])
                p[++tot] = i; // 该数为质数，添加进质数表
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j)
            {
                vis[i * p[j]] = 1; // 将该数的倍数标记为合数
                if (i % p[j] == 0)
                    break; // 如果该数是质数，则不需要再向后遍历
            }
        }
    }

    struct Status
    {
        int f, s; // f为哈希值，s为子树大小
        Status(int f_ = 0, int s_ = 0)
            : f(f_), s(s_) {}
    };

    unordered_map<TreeNode *, Status> hS, hT; // 哈希表，分别存放s和t的哈希值和子树大小

    void dfs(TreeNode *o, unordered_map<TreeNode *, Status> &h)
    {                             // 深度优先搜索，构造哈希表
        h[o] = Status(o->val, 1); // 初始哈希值为该节点的值，子树大小为1
        if (!o->left && !o->right)
            return; // 如果该节点没有子节点，返回
        if (o->left)
        {                                                                            // 如果有左子节点
            dfs(o->left, h);                                                         // 递归处理左子节点
            h[o].s += h[o->left].s;                                                  // 更新子树大小
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD; // 更新哈希值
        }
        if (o->right)
        {                                                                               // 如果有右子节点
            dfs(o->right, h);                                                           // 递归处理右子节点
            h[o].s += h[o->right].s;                                                    // 更新子树大小
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD; // 更新哈希值
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        getPrime(); // 获取质数表
        dfs(s, hS); // 构造s的哈希表
        dfs(t, hT); // 构造t的哈希表

        int tHash = hT[t].f; // 记录t的哈希值
        for (const auto &[k, v] : hS)
        { // 枚举s的每个节点
            if (v.f == tHash)
            {
                return true;
            }
        }
        return false;
    }
};