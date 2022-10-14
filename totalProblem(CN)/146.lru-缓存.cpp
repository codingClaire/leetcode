/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
// 13.26 % 33.69 %
//双向链表节点
struct DLinkedNode
{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr) {}
};

class LRUCache
{
private:
    DLinkedNode* head;
    DLinkedNode* tail;
    unordered_map<int,DLinkedNode*> cache; //key和对应的Node
    int size;
    int capacity;

public:
    //注意这里要更新capacity和size
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }


     int get(int key)
    {
        if(!cache.count(key))
        {//不存在，直接返回-1
            return -1;
        }
        //存在，哈希表定位，移动到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        //cout<<"put"<<endl;
        if(!cache.count(key)) //不存在key
        {
            //cout<<key<<" "<<value<<endl;
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key] = node; // 将key添加到哈希表
            addToHead(node); // 添加到双向链表的头部
            size++;
            if(size > capacity)
            {
                DLinkedNode* removed = removeTail(); //链表删除
                cache.erase(removed->key); // 哈希表也要删除
                delete removed;
                size--;
            }
        }
        else
        {//存在key 哈希定位，修改value，移动到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode* dele = tail->prev;
        removeNode(tail->prev);
        return dele;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
