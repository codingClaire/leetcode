class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long res = 0;
        vector<long long> interval;
        long long curInterval = 1;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] - prices[i + 1] == 1)
            {
                curInterval++;
            }
            else
            {
                interval.emplace_back(curInterval);
                curInterval = 1;
            }
        }
        interval.emplace_back(curInterval);
        long long total = 0;
        for (int i = 0; i < interval.size(); i++)
        {
            total += interval[i];
            res += interval[i] * (interval[i] + 1) / 2;
        }
        return res + prices.size() - total;
    }
};