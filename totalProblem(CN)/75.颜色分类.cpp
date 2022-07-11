    /*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
//[75] 颜色分类
// 双指针 40.59 % 87.23 %
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, one = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[zero], nums[i]);
                if (zero < one)
                {
                    swap(nums[i], nums[one]);
                }
                zero++;
                one++;
            }
            else if (nums[i] == 1)
            {
                swap(nums[one], nums[i]);
                one++;
            }
        }
    }
};
// @lc code=end
// 40.59 % 71.91 %
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int head = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                swap(nums[head], nums[i]);
                head++;
            }
            i++;
        }
        int j = head;
        while (j < nums.size() && head < nums.size())
        {
            if (nums[j] == 1)
            {
                swap(nums[head], nums[j]);
                head++;
            }
            j++;
        }
    }
};