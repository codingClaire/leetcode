/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
// @lc code=end

// 87.34 % 91.2 %
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0, right = 0;
        int len = nums.size();
        while (right != len)
        {
            if (nums[right] != 0)
            {
                swap(nums[right], nums[left]);
                left++;
                right++;
            }
            else
            {
                right++;
            }
        }
    }
};

// 64.01 % 98.25 %
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.begin();
        while (right != nums.end())
        {
            if (*right != 0)
            {
                swap(*right, *left);
                left++;
                right++;
            }
            else
            {
                right++;
            }
        }
    }
};

// 13.2 % 67.06 %
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int>::iterator it = nums.begin();
        int zeronum = 0;
        while (it != nums.end())
        {
            if (*it == 0)
            {
                zeronum++;
                nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        for (int i = 0; i < zeronum; i++)
            nums.emplace_back(0);
    }
};