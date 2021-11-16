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
    void reverseSubList(ListNode *s, int length)
    {
        if (s->next == NULL)
            return;
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
    };
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *virt = new ListNode(0);
        virt->next = head;
        ListNode *w = virt;
        int index = 0;
        while (w)
        {
            if (index % 2 == 0)
                reverseSubList(w, 2);
            w = w->next;
            index++;
        }
        return virt->next;
    }
};