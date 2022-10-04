/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
// 58.91 % 88.91%
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxv = INT_MIN;
        int curmax = 1, curmin = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                int tmp = curmax;
                curmax = curmin;
                curmin = tmp;
            }
            // 这一步交换，简直就是神来之笔，真的有人能想到吗？
            //对于最小值来说，最小值是本身则说明这个元素值比前面连续子数组的最小值还小。相当于重置了阶段最小值的起始位置
            curmax = max(curmax*nums[i],nums[i]);
            curmin = min(curmin*nums[i],nums[i]);

            maxv = max(maxv,curmax);
        }
        return maxv;
    }
};
// @lc code=end
