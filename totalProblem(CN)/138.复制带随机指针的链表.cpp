/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// 20.87 %  5.58 %
class Solution
{
public:
    unordered_map<Node*, Node*> cached;
    Node *copyRandomList(Node *head)
    {
        if(head == NULL)
            return NULL;
        //当前的节点不存在的情况
        if(!cached.count(head))
        {
            Node* new_head = new Node(head->val);
            cached[head] = new_head;
            //递归的写法，很妙！
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        return cached[head];
    }
};
// @lc code=end
