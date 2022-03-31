/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        vector<int> newarray(len);
        for (int i = 0; i < len; i++)
        {
            //新数组的下标是(i+k) % len，类似哈希的思想，很巧妙
            newarray[(i + k) % len]= nums[i];
        }
        nums.assign(newarray.begin(), newarray.end());
    }
};
// @lc code=end
/* TLE解法！！
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        while (k > len)
            k -= len;
        for (int i = len - k; i < len; i++)
        {
            nums.insert(nums.begin() + i - len + k, nums[i]);
            nums.erase(nums.begin() + i + 1);
        }
    }
};
*/