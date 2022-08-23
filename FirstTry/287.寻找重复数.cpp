/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 78.31 %  24.18 % 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //等价于找环的入口
        int slow = 0, fast = 0;
        // 第一阶段
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // 第二阶段：
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// @lc code=end
