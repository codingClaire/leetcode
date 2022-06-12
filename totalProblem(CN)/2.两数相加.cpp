/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
//[2] 两数相加
// 75.65 % 49.75 %
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int bit = 0;
        ListNode *head = nullptr;
        ListNode *tmp = nullptr;
        while (l1 != NULL || l2 != NULL)
        {
            int number1 = (l1 == NULL) ? 0 : l1->val;
            int number2 = (l2 == NULL) ? 0 : l2->val;
            if (!head)
            {
                head = tmp = new ListNode((number1 + number2 + bit) % 10);
            }
            else
            {
                tmp->next = new ListNode((number1 + number2 + bit) % 10);
                tmp = tmp->next;
            }
            // 增加节点之后再更新进位
            bit = (number1 + number2 + bit) / 10;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (bit > 0)
            tmp->next = new ListNode(bit);
        return head;
    }
};
// @lc code=end