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
// 二刷，暴力法 42.27% 77.70%
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == t)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};

// 二刷
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            if (mp.count(t))
                return {mp[t], i};
            mp.insert(make_pair(nums[i], i));
        }
        return {-1, -1};
    }
};