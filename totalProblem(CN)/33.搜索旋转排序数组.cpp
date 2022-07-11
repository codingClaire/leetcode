/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
// 68.08 % 83.6 %
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            { // 前半部分完全有序
                if (nums[0] <= target && target < nums[mid])
                    // target在这个完全有序区间，因此更新right
                    right = mid - 1;
                else
                    // 否则更新left
                    left = mid + 1;
            }
            else
            { //后半部分完全有序
                if (nums[mid] < target && target <= nums[nums.size() - 1])
                    // target在这个完全有序区间，更新left
                    left = mid + 1;
                else
                    // target不在这个区间，更新right，相当于排除后面的
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
