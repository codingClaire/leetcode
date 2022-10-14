/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
//  5.06 % 63.02 %
class Solution
{
private:
        vector<vector<int>> rec; // rec[i][j]表示填满开区间 (i,j)能得到的最多硬币数
    vector<int> val; //添加1 处理左右两侧

public:
    int solve(int left, int right)
    {
        if (left >= right - 1)
            return 0;
        if (rec[left][right] != -1)
        {
            return rec[left][right];
        }
        for (int i = left + 1; i < right; i++)
        {
            // 想象一个指针从left划到right，同时递归调用，计算了sum,rec
            // 和140异曲同工之妙
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            // 维护区间最大值
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        val.resize(n + 2);
        
        for (int i = 1; i <= n; i++)
        {
            val[i] = nums[i - 1];
        }
        val[0] = val[n + 1] = 1;
        //rec的初始化 全部是-1
        rec.resize(n+2,vector<int>(n+2,-1));
        return solve(0,n+1);
    }
};
// @lc code=end

// 70.09 %  81.17 %
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // dp[i][j]表示填满开区间 (i,j)能得到的最多硬币数
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {//左边 从n-1到0
            for (int j = i + 2; j <= n + 1; j++)
            {//右边 起始从n-1到2  到 末尾
                for (int k = i + 1; k < j; k++)
                {//中间 从i+1到j
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};