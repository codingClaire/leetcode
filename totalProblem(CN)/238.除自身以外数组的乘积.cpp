/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
// 90.72% 38.56%
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 节省空间的做法
        int len = nums.size();
        vector<int> res;
        res.emplace_back(1);
        int right = 1; // 右侧的值的类乘
        //res先乘上左侧乘积
        for (int i = 0; i < len - 1; i++)
            res.emplace_back(nums[i] * res[i]);
        //再乘上右侧类乘的积
        for (int i = len - 1; i >= 0; i--)
        {
            res[i] = res[i] * right;
            right = right * nums[i]; //累乘
        }
        return res;
    }
};
// @lc code=end

// 16.63% 5.01%
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> left, right;
        // 分别先算出左侧乘积数组和右侧乘积数组
        left.emplace_back(1);
        right.emplace_back(1);
        for (int i = 0; i < len - 1; i++)
        {
            left.emplace_back(nums[i] * left[i]);
            right.emplace_back(nums[len - 1 - i] * right[i]);
        }
        // 除去当前元素的乘积就用当前元素左侧和右侧的数乘起来即可
        vector<int> res;
        for (int i = 0; i < len; i++)
            res.emplace_back(left[i] * right[len - 1 - i]);
        return res;
    }
};