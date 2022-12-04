/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
// 84.63 % 96.72 %
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        int start = a - 1, interval = b - a + 2;
        while (start--)
        {
            l1 = l1->next;
        }
        ListNode *aPrev = l1;
        while (interval--)
        {
            l1 = l1->next;
        }
        aPrev->next = list2;
        while (l2 != nullptr && l2->next != nullptr)
        {
            l2 = l2->next;
        }
        l2->next = l1;
        return list1;
    }
};
// @lc code=end
