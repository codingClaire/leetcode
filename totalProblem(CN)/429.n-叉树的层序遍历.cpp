/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
// 32.43% 15.34%
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            Node *cur;
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                cur = q.front();
                q.pop();
                tmp.emplace_back(cur->val);
                for (int j = 0; j < cur->children.size(); j++)
                {
                    q.push(cur->children[j]);
                }
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

