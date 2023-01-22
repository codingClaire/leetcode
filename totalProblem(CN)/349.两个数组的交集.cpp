/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
// 41.57% 15.46%
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        vector<int> seen(1000, 0);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (!mp.count(nums1[i]))
                mp[nums1[i]] = 0;
            mp[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp.count(nums2[i]) && seen[nums2[i]] == 0)
            {
                seen[nums2[i]] = 1;
                res.emplace_back(nums2[i]);
            }
        }
        return res;
    }
};
// @lc code=end
