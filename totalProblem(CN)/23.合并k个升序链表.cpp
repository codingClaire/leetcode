/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
//[23] 合并K个升序链表
// 法三：优先队列法（来自评论区）
// 50.7 % 73.1 %
class Solution
{
public:
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    //底层使用的vector < ListNode *> 比较的函数是comp
    priority_queue<ListNode *, vector<ListNode *>, comp> q;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto node : lists)
        {
            if (node)
                q.push(node);
        }
        ListNode *head = new ListNode();
        ListNode *tail = head;
        while (!q.empty())
        {
            //最小的node
            ListNode *node = q.top();
            q.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
                q.push(node->next);
        }
        return head->next;
    }
};
// @lc code=end
// 法二：分治法 77.08 %  12.86 %
// 这个方法的比较次数会少一点，所以更快一些
class Solution
{
public:
    //和21题的逻辑完全一样
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *l1 = list1, *l2 = list2;
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
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
        if (l1 != NULL)
            cur->next = l1;
        else if (l2 != NULL)
            cur->next = l2;
        return res->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;
        int mid = (left + right) >> 1;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};
//法一：16.34 % 68.15 %
class Solution
{
public:
    //和21题的逻辑完全一样
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *l1 = list1, *l2 = list2;
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
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
        if (l1 != NULL)
            cur->next = l1;
        else if (l2 != NULL)
            cur->next = l2;
        return res->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = NULL;
        //两两merge，直到成为一个数组
        for (int i = 0; i < lists.size(); i++)
            ans = mergeTwoLists(ans, lists[i]);
        return ans;
    }
};