class Solution
{
public:
    int bitsum(int n)
    {
        int res = 0;
        while (n != 0)
        {
            res += (n % 10);
            n = n / 10;
        }
        return res;
    }

    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int bits = bitsum(nums[i]);
            if (!mp.count(bits))
                mp.insert(make_pair(bits, vector<int>{nums[i]}));
            else
                mp[bits].emplace_back(nums[i]);
        }
        int maxv = -1;
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (iter->second.size() >= 2)
            {
                sort(iter->second.begin(), iter->second.end());
                int m = iter->second.size();
                maxv = max(maxv, iter->second[m - 1] + iter->second[m - 2]);
            }
        }
        return maxv;
    }
};