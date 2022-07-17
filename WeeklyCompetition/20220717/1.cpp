class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!mp.count(nums[i]))
                mp.insert(make_pair(nums[i], 1));
            else
                mp[nums[i]]++;
        }
        int num1 = 0, num2 = 0;
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (iter->second % 2 == 0)
            {
                num1 += (iter->second / 2);
            }
            else
            {
                num1 += (iter->second / 2);
                num2++;
            }
        }
        return vector<int>{num1, num2};
    }
};