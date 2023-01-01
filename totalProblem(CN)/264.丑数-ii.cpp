/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
// 动态规划法 72.71 % 84.35 %
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1); // dp[i] 表示第 i个丑数
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        // 有点类似三指针的方法
        for (int i = 2; i <= n; i++)
        {
            int num2 = dp[p2] * 2;
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            // 三个指针移动
            // 这里注意:只要ptr(i)负责生成的丑数与dp[i]相等,即取到了dp[ptr(i)]*i就要移动对应指针
            // 例如:2*5=5*2所以相同的丑数可能会被生成多次读取多次,因此要跳过
            // 本质上说就是我们不管哪个参与生成的作为dp[i],有可能num2=num5=10的情况出现
            // 这时我们直接取一次10加入dp[i],然后两个涉及的指针统统移动,那么下一次只会出现3*5/6*2>10
            if (dp[i] == num2)
                p2++;
            if (dp[i] == num3)
                p3++;
            if (dp[i] == num5)
                p5++;
        }
        return dp[n];
    }
};
// @lc code=end
// 最小堆法：21.63 % 15.02 %
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> factors = {2, 3, 5};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int ugly = 0;
        for (int i = 0; i < n; i++)
        {
            // 第n次显然就是第n个丑数
            long curr = heap.top();
            heap.pop();
            ugly = int(curr);
            for (int j = 0; j < 3; j++)
            {
                long next = curr * factors[j];
                if (!seen.count(next))
                {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};