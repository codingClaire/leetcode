/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
// 44.59% 29.83%
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        string tmp = "";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (tmp != "" && tmp != ".")
                    v.emplace_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += path[i];
            }
        }
        if (tmp != "")
            v.emplace_back(tmp);
        vector<string> res;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
            if (v[i] == "..")
            {
                if (res.size() != 0)
                    res.pop_back();
            }
            else if (v[i] != ".")
            {
                res.emplace_back(v[i]);
            }
        }
        if (res.size() == 0)
            return "/";
        string newpath = "";
        for (int i = 0; i < res.size(); i++)
        {
            newpath += ("/" + res[i]);
        }
        return newpath;
    }
};
// @lc code=end
//"/home//foo\t"
