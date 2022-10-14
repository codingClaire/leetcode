/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
 * 请你判断是否可以利用字典中出现的单词拼接出 s。
 * 注意：不要求字典中出现的单词全部都使用，
 * 并且字典中的单词可以重复使用。
 */

// @lc code=start
// 66.13% 53.28%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        auto wordDictSet = unordered_set<string>();
        for(auto word: wordDict)
        {
            wordDictSet.insert(word);
        }
        int slen = s.size();
        auto dp = vector<bool>(slen + 1);
        dp[0] = true;
        // 必须从左到右，因为后面的依赖前面的状态
        for (int i = 1; i <= slen; i++)
        {
            // dp[i]表示0-i的字符串可以被拆分成字典中的单词
            // 开始拆分0-i 拆成0-j和j+1-i 看j+1到i是否在字典里
            // 可以理解为探索的过程
            for(int j=0;j<i;j++)
            {
                if(dp[j]&& wordDictSet.find(s.substr(j,i-j))!=wordDictSet.end())
                {
                    // 只要有一种方案就结束探索
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[slen];
    }
};
// @lc code=end

