/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
// 81.16 %  54.15 %
class Solution 
{
public:
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        // 两个点及以下，肯定可以
        if (n <= 2)
            return n;
        int ret = 0;
        // 每个节点都会计算一次ret
        for (int i = 0; i < n; i++)
        {
            // 直线最多的情况
            if (ret >= n - i || ret > n / 2)
                break;
            unordered_map<int, int> mp; // 斜率数值 - 数量
            for (int j = i + 1; j < n; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                // 一些小细节，比如为0的情况，正负号的情况
                if (x == 0)
                {
                    y = 1;
                }
                else if (y == 0)
                {
                    x = 1;
                }
                else
                {
                    if (y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int gcd_res = gcd(abs(x), abs(y));
                    // 划到最简
                    x /= gcd_res;
                    y /= gcd_res;
                }
                mp[y+x*20001]++; //根据题目的取值范围得到
            }
            int maxn =0;
            for(auto& [_,num]:mp)
            {
                maxn = max(maxn,num+1);
            }
            // 存储最大的ret
            ret = max(ret,maxn);
        }
        return ret;
    }
};
// @lc code=end
