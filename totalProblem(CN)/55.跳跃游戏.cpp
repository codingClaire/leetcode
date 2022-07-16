/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
// 动态规划 87.77 %  94.75 %
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int end = n-1;
		for(int i=n-2; i>=0; i--) 
        {
			if(end - i <= nums[i])
				end = i;
		}
		return end==0;
    }
};
// @lc code=end

// 贪心 39.95 %  87.66 % 
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int largest = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= largest)
            {
                largest = max(largest, i + nums[i]);
                if (largest >= n - 1)
                    return true;
            }
        }
        return false;
    }
};



class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int fIndex = len - 1;
        int dis[len];
        for (int i = 0; i < len; i++)
            dis[i] = 0;
        bool breakFlag = true;
        while (fIndex != 0)
        {
            for (int i = fIndex - 1; i >= 0; i--)
            {
                breakFlag = true;
                dis[i] = fIndex - i;
                if (dis[i] <= nums[i])
                {
                    fIndex = i;
                    breakFlag = false;
                }
            }
            if (breakFlag == true)
                return false;
        }
        return true;
    }
};