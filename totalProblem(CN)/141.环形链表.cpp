/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//  93.66 % 94.82 %
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *fast = head->next, *slow = head;
        // 如果都在head 那么根本不会进循环的！！
        while (fast != slow)
        {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

//  93.66 % 94.82 %
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if (fast == NULL || fast->next == NULL)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// @lc code=end
// 10.22 % 9.57 %
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> mp;
        ListNode *cur = head;
        while (cur != NULL)
        {
            mp.insert(cur);
            cur = cur->next;
            if (mp.count(cur))
            {
                return true;
            }
        }
        return false;
    }
};