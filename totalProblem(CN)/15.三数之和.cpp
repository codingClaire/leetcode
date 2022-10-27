/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
//[15] 三数之和
// 83.11 % 46.06 %
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // 排序
        //1. 定i
        for (int i = 0; i < nums.size(); i++)
        {
            // 当前i已经枚举过的不用考虑
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int k = nums.size() - 1; // k从数组末尾开始枚举
            //2. 定j
            for (int j = i + 1; j < nums.size(); j++)
            {
                //当前j已经枚举过的不用考虑
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 缩小范围 
                // 3. 动k
                while (j < k && nums[j] + nums[k] > target)
                {
                    k--;
                }
                // 更新k之后，才判断它和j是否相等
                if (j == k)
                    break;
                //如果j和k相等，那么这个结果将会被舍弃
                if (nums[j] + nums[k] == target)
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
// @lc code=end
