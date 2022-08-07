/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// [169] 多数元素
//投票算法
// 70.56% 34.53%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == candidate)
                count++;
            else if (--count < 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};
// @lc code=end
//分治法
// 37.80% 5.37%
class Solution
{
    int countNum(vector<int> &nums, int target, int l, int r)
    {
        int count = 0;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] == target)
                count++;
        }
        return count;
    }
    int backtrack(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        int mid = (l + r) / 2;
        int left_num = backtrack(nums, l, mid);
        int right_num = backtrack(nums, mid + 1, r);
        if (countNum(nums, left_num, l, r) > (r - l + 1) / 2)
            return left_num;
        if (countNum(nums, right_num, l, r) > (r - l + 1) / 2)
            return right_num;
        return -1;
    }

public:
    int majorityElement(vector<int> &nums)
    {
        return backtrack(nums, 0, nums.size() - 1);
    }
};
//排序法
// 15% 45%
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};