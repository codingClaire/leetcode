/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
// 排序 + 双指针 + 剪枝
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 加上最小的还是大， 直接不用遍历后面的了
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            // 加上最大的还是小
            if ((long)nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
                continue;
            // i已经固定了
            for (int j = i + 1; j < len - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 最小的两个都不行，直接不用遍历后面的了
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                // 加上最大的还是小
                if ((long)nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target)
                    continue;
                // 开始双指针 j是固定的
                int left = j + 1, right = len - 1;
                while (left < right)
                {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 排除相同元素
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};

// @lc code=end
