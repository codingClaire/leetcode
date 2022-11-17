/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
// 前缀和  20.45% 61.02%
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(int i=0;i<nums.size();i++)
        {
            pre += nums[i];
            if(mp.find(pre-k)!=mp.end())
                count +=mp[pre-k];
            mp[pre]++;
        }
        return count;
    }
};
// @lc code=end
