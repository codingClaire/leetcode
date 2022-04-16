/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// 44.99 %  22.63 %
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *cur = head;
        while (cur != NULL)
        {
            v.emplace_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
        {
            if (v[i] != v[j])
                return false;
        }
        return true;
    }
};
// @lc code=end

// 68.89 % 36.06 %
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *cur = head;
        int length = 0;
        while (cur != NULL)
        {
            cur = cur->next;
            length++;
        }
        vector<int> half;
        cur = head;
        int half_len = length % 2 == 0 ? length / 2 : length / 2 + 1;
        for (int i = 0; i < half_len; i++)
        {
            half.emplace_back(cur->val);
            cur = cur->next;
        }
        int idx = half_len - 1;
        if (length % 2 != 0)
            idx--;
        while (cur != NULL)
            if (cur->val != half[idx])
            {
                return false;
            }
            else
            {
                idx--;
                cur = cur->next;
            }
        return true;
    }
};
//n年前的复杂解法
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *n1 = head;
        ListNode *n2 = head;
        while (n2->next != NULL && n2->next->next != NULL)
        {
            n1 = n1->next;
            n2 = n2->next->next;
        } // n1在中部，n2在结尾
        n2 = n1->next;
        n1->next = NULL; //中部释放
        ListNode *n3 = NULL;
        //反转右半部分
        while (n2 != NULL)
        {
            n3 = n2->next; //保存n2
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1;
        n2 = head;
        // n1在尾 n2在头
        bool res = true;
        while (n1 != NULL && n2 != NULL)
        {
            if (n1->val != n2->val)
            {
                res = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        n1 = n3->next;
        n3->next = NULL;
        while (n1 != NULL)
        { //恢复链表
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return res;
    }
};
