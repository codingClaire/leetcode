/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
// 单调栈 56.75 %  92.52 %
class Solution 
{ 
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> vis(26), num(26);
        for(char ch: s)
            num[ch-'a']++;
        string stk;
        for(char ch: s)
        {
            if(!vis[ch-'a'])
            {   // 没有出现当前的ch
                // 栈不为空，且ch小于栈顶元素（字典序逆序）
                while(!stk.empty() && stk.back() > ch)
                {
                    // 栈顶元素是重复的, 舍弃栈顶
                    if(num[stk.back()-'a'] > 0)
                    {
                        // 更新被舍弃的栈顶的vis
                        vis[stk.back()-'a'] = 0;
                        stk.pop_back();
                    }
                    else
                    { // 栈顶元素是不重复的，不需要任何操作
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch-'a'] -= 1;
        }
        return stk;
    }
};
// @lc code=end

