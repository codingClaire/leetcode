/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
//[162] 寻找峰值
//  58.43 % 23.18 %
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end

//找最大值，真的很机智！
// 100 % 40.13 %
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};

// 58.43 % 88.49 %
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int picked = rand() % nums.size();
        auto get = [&](int i) -> pair<int, int>
        {
            if (i == -1 || i == nums.size())
                return {0, 0};
            return {1, nums[i]};
        };
        while (!(get(picked - 1) < get(picked) && get(picked + 1) < get(picked)))
        {
            if (get(picked - 1) > get(picked))
                picked--;
            else
                picked++;
        }
        return picked;
    }
};