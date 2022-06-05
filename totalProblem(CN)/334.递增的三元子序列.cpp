/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
// [334] 递增的三元子序列 贪心：95.36 % 58.95 %
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > second)
            {
                return true;
            }
            else if (nums[i] > first)
            {
                second = nums[i];
            }
            else
            {
                first = nums[i];
            }
        }
        return false;
    }
};
// @lc code=end
// [334] 递增的三元子序列 双向遍历O(N)：5.7 %  9.7 %
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftmin(n, 0), rightmax(n, 0);
        leftmin[0] = nums[0];
        rightmax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            leftmin[i] = min(nums[i], leftmin[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightmax[i] = max(nums[i], rightmax[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (leftmin[i] < nums[i] && nums[i] < rightmax[i])
                return true;
        }
        return false;
    }
};