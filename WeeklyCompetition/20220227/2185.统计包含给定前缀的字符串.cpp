/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int num = 0;
        for (int i = 0; i < words.size(); i++)
        {
            bool flag = true;
            if (words[i].length() >= pref.length())
            {
                //前缀单词长度要小于待比较的单词
                for (int j = 0; j < pref.length(); j++)
                {
                    if (words[i][j] != pref[j])
                    {
                        flag = false;
                    }
                }
            }
            else
            {
                flag = false;
            }
            if (flag == true)
            {
                //满足条件就累加
                num++;
            }
        }
        return num;
    }
};
// @lc code=end

