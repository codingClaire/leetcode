class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int len = s.size();
        unordered_map<char, int> pos;
        int l = 0;
        int result = 0;
        for (int r = 0; r < len; r++)
        {
            if (pos.count(s[r])) //如果s[r]存在于unordered_map中 返回1
            {
                l = max(l, pos[s[r]] + 1); //更新left 向右移动到s[r]所在位置的下一个位置 因为已经出现过了嘛
            }
            pos[s[r]] = r;                   //设置s[r]
            result = max(result, r - l + 1); //求最大 保存好结果
        }
        return result;
    }
};