/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
//[621] 任务调度器
// 19.83% 41.63%
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t:tasks)
        {
            freq[t]++;
        }
        vector<int> next_valid,rest;
        // next_valid[j]表示任务序列中的第j个任务的下一个可以被执行的时间
        // rest[j]表示任务序列中的第j个任务的还有执行的次数
        for(auto [_,v]:freq)
        {
            next_valid.push_back(1);
            rest.push_back(v);
        }
        int time = 0;
        //按照task序列遍历
        for (int i = 0; i < tasks.size(); i++)
        {
            time++;
            //获取当前最早可以被执行的任务
            int min_valid = INT_MAX;
            for(int j=0;j<freq.size();j++)
            {
                if(rest[j])
                {
                    min_valid = min(min_valid, next_valid[j]);
                }
            }
            //对time进行更新，直接跳过待命状态
            time = max(time, min_valid);
            // 获取可执行的时间比当前时间早（排除冷却的情况）且剩余执行次数最多的任务
            int maxrest=-1;
            for (int j = 0; j < freq.size(); j++)
            {
                if(rest[j]&&next_valid[j]<=time)
                {
                    if (maxrest == -1 || rest[j] > rest[maxrest])
                        maxrest = j;
                }
            }
            // 处理第maxrest个任务
            next_valid[maxrest] = time + n + 1; // 冷却
            rest[maxrest]--; 
        }
        return time;
    }
};
// @lc code=end
////[621] 任务调度器
// 构造法 45.80% 11.28%
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char t : tasks)
        {
            freq[t]++;
        }
        // 最多的执行次数
        // 匿名函数的写法，值得多学学
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto &u, const auto &v)
                                  { return u.second < v.second; })
                                  ->second;
        // 具有最多执行次数的任务数量，即没有填满的最后一行
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto &u)
                                  { return acc + (u.second == maxExec); });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};