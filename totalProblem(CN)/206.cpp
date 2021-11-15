//https://leetcode-cn.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *q = head;
        ListNode *p = q->next;
        if (!p)
            return head;
        q->next = NULL;
        while (p != NULL)
        {
            ListNode *r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        return q;
    }
};