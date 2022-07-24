/*
 * @lc app=leetcode.cn id=2343 lang=cpp
 *
 * [2343] 裁剪数字后查询第 K 小的数字
 */

// @lc code=start
// 100 % 100 %
class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = nums[0].size();
        // vecs[i][j] 表示基数排序第 i 轮中第 j 小的数对应的index
        vector<vector<int>> vecs(m + 1);
        for (int i = 0; i < n; i++)
            vecs[0].push_back(i);
        for (int i = 1; i <= m; i++)
        {
            vector<vector<int>> Bin(10);
            // 把第 i - 1 轮的结果，根据 nums 中右数第 i 位数，依次放入桶中
            for (int j = 0; j < vecs[i - 1].size(); j++)
            {
                int index = vecs[i - 1][j];
                Bin[nums[index][m - i] - '0'].push_back(index);
            }

            // 把每个桶的结果连接起来，成为第 i 轮的结果
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < Bin[j].size(); k++)
                    vecs[i].push_back(Bin[j][k]);
            }
        }
        //在这之前把所有的都计算完成，这样就可以不用考虑恢复的问题了，非常机智
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int k = queries[i][0], trim = queries[i][1];
            ans.push_back(vecs[trim][k - 1]);
        }
        return ans;
    }
};
// @lc code=end

// TLE version
class Solution
{
public:
    static bool cmp(string &a, string &b)
    {
        return a < b;
    }
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<string> copynums;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < queries.size(); i++)
        {
            int k = queries[i][0], trim = queries[i][1];
            copynums.assign(nums.begin(), nums.end());
            // trim
            for (int j = 0; j < n; j++)
            {
                int length = nums[j].length();
                if (trim != 0)
                    nums[j] = nums[j].substr(length - trim, trim);
            }
            // find k
            unordered_map<string, vector<int>> mp;
            for (int j = 0; j < nums.size(); j++)
            {
                if (!mp.count(nums[j]))
                    mp.insert(make_pair(nums[j], vector<int>{j}));
                else
                    mp[nums[j]].emplace_back(j);
            }
            sort(nums.begin(), nums.end(), cmp);
            string knum = nums[k - 1];
            int s = 0;
            for (int j = k - 2; j >= 0; j--)
            {
                if (nums[j] == knum)
                    s++;
                else
                    break;
            }
            //  recover
            int index = -1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (nums[j] == knum)
                {
                    sort(mp[knum].begin(), mp[knum].end());
                    index = mp[knum][s];
                }
                nums[j] = copynums[j];
            }
            res.emplace_back(index);
        }
        return res;
    }
};