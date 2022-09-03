/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
//法二： 自底向上的归并排序
// 68.67% 68.52%
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        int length = 0;
        // 获取链表长度
        ListNode *node = head;
        while (node != nullptr)
        {
            length++;
            node = node->next;
        }
        ListNode *dummyHead = new ListNode(0, head);
        //每次拆分为subLen的若干个链表，每次合并两个
        for (int subLen = 1; subLen < length; subLen <<= 1)
        {
            ListNode *prev = dummyHead;
            ListNode *cur = dummyHead->next; // 拆分链表的位置
            while (cur != nullptr)
            {
                // 拆分链表1
                // cur初始的位置就是第一个链表的头
                ListNode *head1 = cur; 
                for (int i = 1; i < subLen && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }
                //拆分链表2
                ListNode *head2 = cur->next;
                cur->next = nullptr; // 断开第一个链表和第二个链表的链接
                cur = head2; // 重新赋值cur
                for (int i = 1; i < subLen && cur != nullptr && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }
                // next用于记录拆分完两个链表的结束位置
                ListNode *next = nullptr;
                if (cur != nullptr)
                {
                    next = cur->next;
                    cur->next = nullptr;
                }
                //合并两个有序链表
                ListNode *merged = merge(head1, head2);
                // prev从两个链表的头开始，移动到合并后的链表末尾
                prev->next = merged;
                while (prev->next != nullptr)
                {
                    prev = prev->next;
                }
                cur = next;
            }
        }
        return dummyHead->next;
    }

    //合并链表，老题目，第21题
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        ListNode *l1 = head1, *l2 = head2;
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 一定要记得补充后面的
        if (l1 != NULL)
        {
            cur->next = l1;
        }
        else if (l2 != NULL)
        {
            cur->next = l2;
        }
        return dummyHead->next;
    }
};
// @lc code=end
//法一： 自顶向下用归并排序
//用快慢指针找中点
//子链表分别排序
//排序后再合并
// 54.07% 23.52%
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return head;
        // 左开右闭，所以这个情况不需要tail
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        //快慢指针找中点
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    //合并链表，老题目，第21题
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        ListNode *l1 = head1, *l2 = head2;
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 一定要记得补充后面的
        if (l1 != NULL)
        {
            cur->next = l1;
        }
        else if (l2 != NULL)
        {
            cur->next = l2;
        }
        return dummyHead->next;
    }
};