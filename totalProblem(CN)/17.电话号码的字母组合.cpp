/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
//[17] 电话号码的字母组合
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
