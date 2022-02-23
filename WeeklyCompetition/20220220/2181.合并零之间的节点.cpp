/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *tail = head; //指向最后一个节点
        while (tail->next != NULL)
            tail = tail->next;

        ListNode *tmp = head;
        ListNode *newnode = head;
        while (tmp != tail)
        {
            newnode = tmp; //newnode指向值为0的节点
            tmp = tmp->next;
            while (tmp->val != 0)
            {
                //将tmp指向的节点累加到newnode
                newnode->val += tmp->val;
                ListNode *delenode = tmp; //保留指针
                tmp = tmp->next; //移动至下一个节点
                delenode->next = NULL; //删除节点
                newnode->next = tmp; //更新newnode
            }
        }
        newnode->next = NULL;
        return head;
    }
};
// @lc code=end

