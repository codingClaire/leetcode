class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        vector<int> sumv;
        int cur = 0;
        sumv.emplace_back(cur);
        for (const auto &num : nums)
        {
            cur += num;
            sumv.emplace_back(cur);
        }
        for (const auto &q : queries)
        {
            int i = 0;
            while (i < sumv.size() && sumv[i] < q)
            {
                i++;
            }
            if (i == sumv.size() || sumv[i] > q)
                i--;
            res.emplace_back(i);
        }
        return res;
    }
};