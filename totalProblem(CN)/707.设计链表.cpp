/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
//5.43 %
class MyLinkedList
{
public:
    struct LNode
    {
        int val;
        LNode *next;
        LNode() : val(0), next(nullptr) {}
        LNode(int x) : val(x), next(nullptr) {}
        LNode(int x, LNode *next) : val(x), next(next) {}
    };
    LNode *dummyhead;

    MyLinkedList()
    {
        dummyhead = new LNode();
    }

    int get(int index)
    {
        int tmpindex = index + 1;
        LNode *tmp = dummyhead;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            tmpindex--;
            if (tmpindex == 0)
                return tmp->val;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        LNode *tmp = dummyhead;
        LNode *newNode = new LNode(val, tmp->next);
        dummyhead->next = newNode;
    }

    void addAtTail(int val)
    {
        LNode *tmp = dummyhead;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        LNode *newNode = new LNode(val);
        tmp->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index <= 0)
            addAtHead(val);
        else
        {
            LNode *tmp = dummyhead;
            int tmpindex = index;
            while (tmp != nullptr)
            {
                tmp = tmp->next;
                tmpindex--;
                if (tmpindex == 0)
                    break;
            }
            // index小于等于链表的长度 这里卡了
            if (tmpindex >= 0 && tmp != nullptr)
            {
                LNode *newNode = new LNode(val, tmp->next);
                tmp->next = newNode;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        int tmpindex = index;
        LNode *tmp = dummyhead;
        while (tmp->next != nullptr)
        {
            if (tmpindex == 0)
                break;
            tmpindex--;
            tmp = tmp->next;
        }
        if (tmpindex == 0 && tmp->next != nullptr)
            tmp->next = tmp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
