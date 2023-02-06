/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

// @lc code=end
class Solution
{
public:
    int search(vector<int> &nums, int target)

    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            cout << mid << " " << nums[mid] << endl;
            if (target < nums[mid])
                right = mid;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }
        return nums[left] == target ? left : -1;
    }
};