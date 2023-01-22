/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start

// DP 100 % 41.37 %
class Solution
{
public:
    vector<int> countBits(int n)
    {
        // 偶数等于其一半的值
        // 奇数则等于其上一个值加一
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++)
        {
            // i &1, 奇数得到1，偶数得到0
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
// @lc code=end

// Brian Kernighan算法 100 % 5.03 %
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int number = i;
            int tmp = 0;
            while (number)
            {
                tmp++;
                number = number & (number - 1);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};

// 普通写法 37.75 % 27.22 %
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int number = i;
            int tmp = 0;
            for (int bit = 0; bit < 32; bit++)
            {
                tmp += (number & 1);
                number = number >> 1;
            }
            // cout<<tmp<<endl;
            res.emplace_back(tmp);
        }
        return res;
    }
};