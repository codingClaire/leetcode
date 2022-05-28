/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
//[20] 有效的括号
// 100 % 53.13 %
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                char match = st.top();
                st.pop();
                if (s[i] == ')' && match != '(')
                    return false;
                if (s[i] == ']' && match != '[')
                    return false;
                if (s[i] == '}' && match != '{')
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
// @lc code=end
