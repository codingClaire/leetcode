/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
// [155] 最小栈
// two stack
// 15.53 % 68.56 %
class MinStack
{
    stack<int> st;
    stack<int> min_st;

public:
    MinStack()
    {
        min_st.push(INT_MAX);
    }

    void push(int x)
    {
        st.push(x);
        min_st.push(min(min_st.top(), x));
    }

    void pop()
    {
        st.pop();
        min_st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
// [155] 最小栈
// vector<int>
// 5.1 % 72.11 %
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        this->nums.emplace_back(val);
    }

    void pop()
    {
        this->nums.erase(this->nums.end() - 1);
    }

    int top()
    {
        return this->nums[nums.size() - 1];
    }

    int getMin()
    {
        auto pos = min_element(this->nums.begin(), this->nums.end());
        int minValue = *pos;
        return minValue;
    }

private:
    vector<int> nums;
};
