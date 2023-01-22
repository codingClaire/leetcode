/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
// 递归写法： 72.73 % 5.23 %
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if(head == nullptr)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val? head->next: head;
    }
};
// @lc code=end
// 35.51 % 64.05 %
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *temp = dummyHead;
        // 不需要对尾结点做特别的处理
        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
            {

                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};
//[2,7,7,7,7]\n7  [2,7,7]
// [ 7, 7, 7, 7 ]\n7
//[ 7, 3, 3, 7 ]\n7
//wrong answer
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;
        // first
        if (head->val == val)
            head = head->next;
        // inner
        ListNode *cur = head;
        ListNode *nextcur = head->next;
        while (nextcur != nullptr && nextcur->next != nullptr)
        {
            // cout << cur->val << " " << nextcur->val << endl;
            if (nextcur->val == val)
            {
                nextcur = nextcur->next;
                cur->next = cur->next->next;
            }
            cur = cur->next;
            nextcur = nextcur->next;
        }
        if (nextcur != nullptr && nextcur->val == val)
        {
            cur->next = nullptr;
        }
        return head;
    }
};