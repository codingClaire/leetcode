/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// 100 % 97.9 %
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode* l1=list1;
        ListNode* l2=list2;
        //dummy node
        ListNode* res = new ListNode(-1);
        ListNode* cur=res;
        while(l1!=NULL && l2!=NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(l1!=NULL)
        {
            cur->next=l1;
        }
        else if (l2!=NULL)
        {
            cur->next=l2;
        }
        return res->next;
    }
};
// @lc code=end

