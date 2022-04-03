/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp.count(nums1[i]))
                mp[nums1[i]]++;
            else
                mp.insert(make_pair(nums1[i], 1));
        }
        //第二个数组
        for (int i = 0; i < nums2.size(); i++)
        {
            if (mp.count(nums2[i]) && mp[nums2[i]] > 0)
            {
                res.emplace_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end
