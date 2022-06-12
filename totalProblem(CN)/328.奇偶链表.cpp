/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
//[328] 奇偶链表
// 100 % 28.6 %
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == NULL || head->next == NULL || head ->next->next ==NULL)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *evenHead = head->next;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next = even->next; // delete even node 
            odd = odd->next; // shift odd node
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end
