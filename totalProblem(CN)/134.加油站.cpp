/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
// 61.53% 24.47%
// 直观理解，不用公式推导。
//可以这样想：假设从x加油站出发经过z加油站最远能到达y加油站，
//那么从z加油站直接出发，不可能到达y下一个加油站。
//因为从x出发到z加油站时可能还有存储的油，这都到不了y的下一站，
//而直接从z出发刚开始是没有存储的油的，所以更不可能到达y的下一站。
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            int total_gas = 0, total_cost = 0;
            int cnt = 0;
            while (cnt < n)
            {
                // 环形的index
                int j = (i + cnt) % n;
                total_gas += gas[j];
                total_cost += cost[j];
                if (total_cost > total_gas)
                    break;
                cnt++;
            }
            if (cnt == n)
                return i;
            else
            { // 直接从不能达到的开始走就行
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
