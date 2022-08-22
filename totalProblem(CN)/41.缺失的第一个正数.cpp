/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
//[41] 缺失的第一个正数
// 99.89 % 99.23 %
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            //遍历一次恰好能够把所有的元素归位
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            // 当前的数不是index+1
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
// @lc code=end
// 99.63 %  99.17 %
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // 非正数都先设置为n+1，便于后续用标记
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            if (num <= n)
            {
                //负号起到标记的作用
                //第num-1个元素的正负性用于确定第num个整数是存在的
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};