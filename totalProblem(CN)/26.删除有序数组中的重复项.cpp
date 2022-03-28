/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        //双指针i,j
        int j=0;
        for (int i=1; i<len;i++){
            if(nums[i]!=nums[i-1]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};
// @lc code=end

//[0,0,1,1,1,2,2,3,3,4]