/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
// 100 % 59.08 % 
class Solution
{
private:
    unordered_set<string> wordSet;
    unordered_map<int, vector<string>> ans; // 当前下标- 从当前下标开始可以组成的句子列表

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0]; // 返回最开始的一个
    }

    void backtrack(const string &s, int index)
    {
        // index是起始
        if (!ans.count(index))
        {
            if (index == s.size())
            {
                ans[index] = {""};
                return;
            }
        
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); i++)
            {
                //word是index开始，i结束的子串 [index,i)
                //i从index开始遍历
                string word = s.substr(index, i - index);
                if (wordSet.count(word))
                {
                    // 往下找的过程
                    backtrack(s, i);
                    //枚举ans[i]的句子列表容器
                    // 因为是backtrack，所以会从ans开始更新（也可以理解成一种恢复）
                    for (const string &succ : ans[i])
                    {
                        // 当前词汇列表为空，就只添加word，否则添加word和之前的句子列表
                        // 这样就会连接在一起
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
    }
};

// @lc code=end
