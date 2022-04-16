/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// 48.84 % 77.47 %
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        ListNode *taildummy = new ListNode(0, NULL);
        tail->next = taildummy;
        // reverse
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *r = head->next->next;
        //第二次写，这里很重要，如果不把它设为NULL，就可能会出现一个环状的连表
        p->next = NULL;
        while (r != NULL)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        return p;
    }
};
// @lc code=end
// 48.84 % 35.38 %
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

//简单的写法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};