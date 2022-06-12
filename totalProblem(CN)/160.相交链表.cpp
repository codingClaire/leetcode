/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
//[160] 相交链表
// 97.26 % 74.33 %
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB== NULL)
            return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA!=pB)
        {
            if(pA == NULL)
                pA = headB;
            else 
                pA = pA->next;
            if (pB == NULL)
                pB = headA;
            else
                pB = pB->next;
        }
        return pA;
    }
};
// @lc code=end
//[160] 相交链表
// 19.91 %  11.84 %
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> hashmap;
        ListNode *tmp = headA;
        while (tmp != NULL)
        {
            hashmap.insert(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp != NULL)
        {
            if (hashmap.count(tmp))
            {
                return tmp;
            }
            tmp = tmp->next;
        }
        return NULL;
    }
};