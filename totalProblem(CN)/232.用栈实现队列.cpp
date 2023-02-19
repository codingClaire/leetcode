/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
// 31.60% 98.62%
class MyQueue
{
public:
    bool flag = 0;
    vector<int> s0, s1;
    MyQueue()
    {

    }

    void push(int x)
    {
        if (flag == 0)
            s0.emplace_back(x);
        else
        {
            int s1len = s1.size();
            for (int i = s1len - 1; i >= 0; i--)
            {
                s0.emplace_back(s1[i]);
                s1.pop_back();
            }
            s0.emplace_back(x);
            flag = 0;
        }
    }

    int pop()
    {
        if (flag == 0)
        {
            int s0len = s0.size();
            for (int i = s0len - 1; i > 0; i--)
            {
                s1.emplace_back(s0[i]);
                s0.pop_back();
            }
            int res = s0[0];
            s0.pop_back();
            flag = 1;
            return res;
        }
        else
        {
            int res = s1[s1.size() - 1];
            s1.pop_back();
            return res;
        }
    }

    int peek()
    {
        if (flag == 0)
        {
            return s0[0];
        }
        else
        {
            return s1[s1.size() - 1];
        }
    }

    bool empty()
    {
        return s1.size() + s0.size() == 0;
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
