/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
// 5.92 % 80.8 %
class Solution 
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> pre;
        if(root== nullptr)
            return pre;
        stack<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.top();
            q.pop();
            pre.emplace_back(node->val);
            int childsize = node->children.size();
            for (int i = childsize-1; i>=0; i--)
            {
                q.push(node->children[i]);
            }
        }
        return pre;        
    }
};
// @lc code=end

// 30.8 % 93.87 %
class Solution
{
public:
    void recursive(vector<int> &pre, Node *root)
    {
        if (root == nullptr)
            return;
        pre.emplace_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            recursive(pre, root->children[i]);
        }
    }

    vector<int> preorder(Node *root)
    {
        vector<int> pre;
        recursive(pre, root);
        return pre;
    }
};