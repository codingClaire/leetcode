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