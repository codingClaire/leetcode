/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
// 二刷 70.92 %  98.13 % 
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // 有点理解为什么直接取第一个就行，因为不管第一个是长是短，前缀肯定都在是第一个单词的子串
        if(!strs.size())
            return "";
        int length = strs[0].size();
        int count =strs.size();
        for(int i=0;i<length;i++)
        {
            char c = strs[0][i];
            //cout<<c<<endl;
            // 接着就是比较每一个单词
            for(int j=1;j<count;j++)
            {
                //cout<<j<<" "<<strs[j]<<endl;
                // 如果出现不等于的就return，这个很好理解
                // 如果当前strs[j]的长度恰好等于当前的i，也返回，这是因为如果到达这一步，说明
                // j从第一个strs[j][0]到最后一个字母strs[j][i-1]都是所有单词的前缀，因此就可以返回了
                if(i==strs[j].size() || strs[j][i]!=c)
                    return strs[0].substr(0,i);

            }
        }
        return strs[0];
    }
};
// @lc code=end



// 100.00% 99.21%
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = strs[0];
        int j = 0;
        int num = 1;
        if (strs.size() == 1)
            return res;
        while (j < res.size())
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (j > strs[i].length())
                {
                    continue;
                }
                if (strs[i][j] == res[j])
                {
                    num += 1;
                }
                else
                {
                    return res.substr(0, j);
                }
                if (num == strs.size())
                {
                    j++;
                    num = 0;
                }
            }
        }
        return res;
    }
};