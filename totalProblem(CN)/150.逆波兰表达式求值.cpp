/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
//[150] 逆波兰表达式求值
// 97.77 % 54.45%
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            string &token = tokens[i];
            if (isNumber(token))
            {
                stk.push(atoi(token.c_str()));
            }
            else
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0])
                {
                case '+':
                    stk.push(num1 + num2);
                    break;
                case '-':
                    stk.push(num1 - num2);
                    break;
                case '*':
                    stk.push(num1 * num2);
                    break;
                case '/':
                    stk.push(num1 / num2);
                    break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string &token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

// @lc code=end
// 97.77 % 54.45%
//  没事了，是写错了
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> q;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int res;
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                if (tokens[i] == "+")
                    res = b + a;
                else if (tokens[i] == "-")
                    res = b - a;
                else if (tokens[i] == "*")
                    res = b * a;
                else
                    res = b / a;
                // cout<<res<<endl;
                q.push(res);
            }
            else
            {
                q.push(stoi(tokens[i]));
            }
        }
        return q.top();
    }
};

/*
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int idx = 0;
        while(idx!=tokens.size())
        {
            string& token = tokens[idx];
            if (!(token == "+" || token == "-" || token == "*" || token == "/"))
                st.push(stoi(tokens[idx]));
            else
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (token[0] == '+')
                {
                    st.push(num1 + num2);
                }
                else if(token[0]  == '-')
                {
                    st.push(num1 - num2);
                }
                else if (token[0]  == '*')
                {
                    st.push(num1 * num2);
                }
                else if (token[0]  == '/')
                {
                    st.push(num1 / num2);
                }
            }
            idx++;
        }
        return st.top();
    }
};


*/