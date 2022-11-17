/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
// 79.60% 91.66%
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int best = 1e7;
        auto update = [&](int cur)
        {
            if (abs(cur - target) < abs(best - target))
                best = cur;
        };
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                update(sum);
                if (sum > target)
                {
                    int k0 = k - 1;
                    while (k0 > j && nums[k0] == nums[k])

                        k0--;

                    k = k0;
                }
                else
                {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        j0++;
                    j = j0;
                }
            }
        }
        return best;
    }
};
// @lc code=end
