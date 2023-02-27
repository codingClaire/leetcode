/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 99.31 % 60.12 %
class Solution
{
public:
    void recursive(vector<int> &pre, Node *root)
    {
        if (root == nullptr)
            return;
        for (int i = 0; i < root->children.size(); i++)
        {
            recursive(pre, root->children[i]);
        }
        pre.emplace_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> pre;
        recursive(pre, root);
        return pre;
    }
};
// @lc code=end
