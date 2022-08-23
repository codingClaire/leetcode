/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
// 46.51 %  23.5%
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int res=0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        for(auto& num: st)
        {
            if(!st.count(num-1))
            {
                int curNum = num;
                int curLen = 1;
                while(st.count(curNum+1))
                {
                    curNum++;
                    curLen++;
                }
                res = max(res,curLen);
            }
        }
        return res;
    }
};
// @lc code=end
