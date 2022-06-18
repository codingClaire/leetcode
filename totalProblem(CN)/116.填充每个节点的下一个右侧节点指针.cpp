/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// [116] 填充每个节点的下一个右侧节点指针
// 52.53 % 97.47 %
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        Node *leftmost = root;
        while (leftmost->left != nullptr)
        {
            Node *head = leftmost;
            while (head != nullptr)
            {
                head->left->next = head->right;
                if (head->next != nullptr)
                    head->right->next = head->next->left;
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
// @lc code=end
// [116] 填充每个节点的下一个右侧节点指针
// 20.65 % 36.43 %
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        Node *res = root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++)
            {
                Node *node = q.front();
                q.pop();
                if (i < curSize - 1)
                    node->next = q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};
