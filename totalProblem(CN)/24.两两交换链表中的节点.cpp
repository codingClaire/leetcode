/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
// 复习: 100% 35.7 %
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead; // p的位置处于每次交换的前驱节点
        while (p->next != nullptr && p->next->next != nullptr)
        {
            ListNode *q = p->next;
            ListNode *r = q->next;
            // 三个步骤
            p->next = r;
            q->next = r->next;
            r->next = q;
            // 移动
            p = q;
        }
        return dummyHead->next;
    }
};
// @lc code=end

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