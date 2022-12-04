/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
// 18.87 % 82.25 % 
class Solution
{
private:
    vector<string> wordsRev;                 // 回文的单词
    unordered_map<string_view, int> indices; //回文单词：位置

public:
    int findWord(const string_view &s, int left, int right)
    {
        auto iter = indices.find(s.substr(left, right - left + 1));
        return iter == indices.end() ? -1 : iter->second;
    }

    bool isPalindrome(const string_view &s, int left, int right)
    {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++)
        {
            if (s[left + i] != s[right - i])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        for (const string &word : words)
        {
            wordsRev.push_back(word);
            reverse(wordsRev.back().begin(), wordsRev.back().end());
        }
        for (int i = 0; i < n; i++)
        {
            indices.emplace(wordsRev[i], i);
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            //遍历第i个单词
            int m = words[i].size();
            if (!m)
                continue;
            string_view wordView(words[i]);
            for (int j = 0; j <= m; j++)
            {
                if (isPalindrome(wordView, j, m - 1))
                {
                    // (j,m+1)是回文串的情况
                    // 能找到word
                    int left_id = findWord(wordView, 0, j - 1);
                    // 找得到而且不是当前的word
                    if (left_id != -1 && left_id != i)
                    {
                        res.push_back({i, left_id});
                    }
                }
                if (j && isPalindrome(wordView, 0, j - 1))
                {
                    // (0,j-1) 是回文串的情况
                    // 能找到对应的word
                    int right_id = findWord(wordView, j, m - 1);
                    // 找得到而且不是当前的word
                    if (right_id != -1 && right_id != i)
                    {
                        res.push_back({right_id, i});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
