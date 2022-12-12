/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
// 用栈，这个想到了就非常简单了！！
// 57.40% 36.24%
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for(auto &ch: s)
        {
            if(st.empty() || st.top() != ch)
                st.push(ch);
            else
                st.pop();
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end
