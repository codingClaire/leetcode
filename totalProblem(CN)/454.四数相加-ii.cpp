/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
//[454] 四数相加 II
// 17.04 % 24.09 %
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        /*
        核心的思路很简单，把四个数分成两组即可，然后用哈希存储前两个数的和
        再用后两个数的的的相反数确定是否键值存在在哈希表中
        */
        int res = 0;
        unordered_map<int, int> mp;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ++mp[nums1[i] + nums2[j]];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mp.count(-nums3[i] - nums4[j]))
                    res += mp[-nums3[i] - nums4[j]];
            }
        }
        return res;
    }
};
// @lc code=end
