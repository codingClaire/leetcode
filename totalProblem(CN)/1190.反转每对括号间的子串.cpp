/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
// 100 % 30.53 % 快速的栈写法
// TODO: 预处理的写法
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> stk;
        string str;
        for (auto &ch : s)
        {
            if (ch == '(')
            {
                stk.push(str);
                str = "";
            }
            else if (ch == ')')
            {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else
            {
                str.push_back(ch);
            }
        }
        return str;
    }
};
// @lc code=end
// 38.93 % 35.88 % 傻瓜写法
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                vector<int> tmp;
                while (st.top() != '(')
                {
                    tmp.emplace_back(st.top());
                    st.pop();
                }
                st.pop();
                for (int j = 0; j < tmp.size(); j++)
                {
                    st.push(tmp[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};