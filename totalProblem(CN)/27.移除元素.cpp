/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
//100 % 37.91 %
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left=0, right=nums.size();
        while(left<right)
        {
            if(nums[left]==val)
            {
                nums[left]=nums[right-1];
                right--;
            }
            else
            {
                left++;
            }
        }
        return left; 
    }
};
// @lc code=end
// 100 %   33.24 %
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left=0, right=0;
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]!=val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left; 
    }
};