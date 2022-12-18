/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
// 56.83 % 55.47 %
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if(head == nullptr)
            return;
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1,l2);
    }

    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // 返回最后，也就是链表头
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while(l1!=nullptr && l2!=nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp; // 用l1_tmp保存新的l1头
            l2->next = l1;
            l2 = l2_tmp; // 用l2_tmp保存新的l2头
        }
    }
};
// @lc code=end
