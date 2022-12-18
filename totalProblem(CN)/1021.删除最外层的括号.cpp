/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
// 68.58 % 50.17 %
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        stack<char> st;
        for(auto c: s)
        {
            // 三个顺序真的 太妙了
            if(c ==')')
                st.pop();
            // 如果非空，就可以放东西了，因为只是要删除外层
            if(!st.empty())
                res.push_back(c);
            if(c=='(')
                st.emplace(c);
        }
        return res;
    }
};
// @lc code=end
