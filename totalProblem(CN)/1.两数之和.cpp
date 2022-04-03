/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// 92.11 % 48.25 %
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int left_part = target - nums[i];
            if (mp.count(left_part))
            {
                res.emplace_back(i);
                res.emplace_back(mp[left_part]);
                break;
            }
            else
            {
                mp.insert(make_pair(nums[i], i));
            }
        }
        return res;
    }
};
// @lc code=end
