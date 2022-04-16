/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// 100 % 34.75 %
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }
        int pre_pos = length - n - 1;
        ListNode *dele = head;
        if (pre_pos < 0)
        {
            return head->next;
        }
        while (pre_pos--)
        {
            dele = dele->next;
        }
        p = dele->next;
        dele->next = p->next;
        return head;
    }
};

// @lc code=end
//简化了，添加dummy node
// 77.61 %   36.6 %
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *p = dummy;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }
        int pre_pos = length - n - 1;
        ListNode *dele = dummy;
        while (pre_pos--)
        {
            dele = dele->next;
        }
        dele->next = dele->next->next;
        return dummy->next;
    }
};
//优雅双指针解法
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        //超前n
        for (int i = 0; i < n; ++i)
        {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};