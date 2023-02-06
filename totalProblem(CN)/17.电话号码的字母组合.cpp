/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
//[17] 电话号码的字母组合
// 二刷，简单
class Solution
{
public:
    void backstrack(unordered_map<int, string> &mp, string &digits, vector<string> &res, string &tmp)
    {
        if (digits.size() == 0)
            res.emplace_back(tmp);
        string s = mp[digits[0] - '0'];
        for (auto &ch : s)
        {
            string new_digits = digits.substr(1, digits.size() - 1);
            tmp.push_back(ch);
            backstrack(mp, new_digits, res, tmp);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<int, string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};
        vector<string> res;
        if (digits.length() == 0)
            return res;
        string tmp = "";
        backstrack(mp, digits, res, tmp);
        return res;
    }
};

// 100 % 5 %
class Solution
{
public:
    void backtrack(vector<string> &res, string &tmp, 
                    unordered_map<int, string> mp, string digits, int index)
    {
        if(index == digits.length())
        {
            res.emplace_back(tmp);
        }
        else
        {
            int num = digits[index]-'0';
            string letter = mp[num];
            for(int i=0;i<letter.length();i++)
            {
                tmp.push_back(letter[i]);
                backtrack(res,tmp,mp,digits,index+1);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<int, string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};

        vector<string> res;
        if (digits.length() == 0)
            return res;
        string tmp;
        backtrack(res, tmp, mp, digits, 0);
        return res;
    }
};
// @lc code=end
