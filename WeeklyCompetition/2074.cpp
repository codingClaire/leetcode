#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *s = head;
        int total = 0, idx = 0, times = 1;
        ListNode *k = head;
        while (k)
        {
            total++;
            k = k->next;
        }
        while (s)
        {
            if (idx + 1 == times * (times + 1) / 2)
            {
                times++;
                total -= times;
                if (total <= 0)
                {
                    if ((total + times - 1) % 2 == 0)
                        reverseSubList(s, total + times);
                    break;
                }
                if (times % 2 == 0)
                    reverseSubList(s, times);
            }
            s = s->next;
            idx++;
        }
        return head;
    }
};

int main()
{

    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(0);
    ListNode *d = new ListNode(5);
    ListNode *e = new ListNode(1);

    ListNode *f = new ListNode(2);
    ListNode *g = new ListNode(7);
    ListNode *h = new ListNode(8);
    ListNode *i = new ListNode(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;
    ListNode *r = a;
    while (r)
    {
        std::cout << r->val << " ";
        r = r->next;
    }
    std::cout << std::endl;
    Solution S;
    r = S.reverseEvenLengthGroups(a);
    std::cout << std::endl
              << "after reverse:" << std::endl;
    while (r)
    {
        std::cout << r->val << " ";
        r = r->next;
    }
    return 0;
}