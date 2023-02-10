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

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0)
            {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) 
                    right--;
                while (right > left && nums[left] == nums[left + 1]) 
                    left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {// 恰好等于target
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};