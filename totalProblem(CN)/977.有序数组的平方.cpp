
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
//80.72 % 95.13 %
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int left =0,right =n-1;
        int pos = n-1;
        while (left<=right)
        {
            if(nums[left]*nums[left]>nums[right]*nums[right])
            {
                res[pos] = nums[left] * nums[left];
                left++;
            }
            else
            {
                res[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        return res;
    }
};
// @lc code=end



//80.72 % 95.13 %
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        int right = n - 1;
        int cur = n - 1;
        while (left <= right)
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                res[cur] = nums[right] * nums[right];
                right--;
            }
            else
            {

                res[cur] = nums[left] * nums[left];
                left++;
            }
            cur--;
        }
        return res;
    }
};