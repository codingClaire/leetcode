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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *virt = new ListNode(0);
        virt->next = head;
        left++;
        right++;
        int length = right - left + 1;
        int lhs = left - 2;
        ListNode *s = virt;
        //while(lhs)
        //s=s->next;
        for (int i = 0; i < lhs; ++i)
            s = s->next;
        ListNode *q = s->next;
        ListNode *m = s->next;
        while (length-- && m)
            m = m->next;
        ListNode *p = q->next;
        while (p != m && p)
        {
            ListNode *r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        s->next->next = p;
        s->next = q;
        return virt->next;
    }
