/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
//  100 % 87.09 %
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int len = s.length();
        if(len<2)
            return len;
        int res =0;
        int left=0,right=0;
        int maxCount = 0;
        vector<int> freq(26,0);
        int index =0;
        while(right<len)
        {
            freq[s[right]-'A']++;
            // maxCount是当前频数最高的字母出现的频次
            maxCount = max(maxCount, freq[s[right]-'A']);
            right++;
            // 总长度如果大于 频数最高的加上最多可修改的次数
            if(right-left>maxCount+k)
            {
                freq[s[left]-'A']--;
                left++;
            }
            res =max(res,right-left);
        }
        return res;
    }
};
// @lc code=end
