class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> odd;
        vector<int> even;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
                even.emplace_back(nums[i]);
            else
                odd.emplace_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int oddLen = odd.size(), evenLen = even.size();
        vector<int> res;

        if (oddLen > evenLen)
        {
            for (int i = 0; i < oddLen - 1; i++)
            {
                res.emplace_back(odd[i]);
                res.emplace_back(even[evenLen - 1 - i]);
            }
            res.emplace_back(odd[oddLen - 1]);
        }
        else if (evenLen > oddLen)
        {
            for (int i = 0; i < evenLen - 1; i++)
            {
                res.emplace_back(even[i]);
                res.emplace_back(odd[oddLen - 1 - i]);
            }
            res.emplace_back(even[evenLen - 1]);
        }
        else
        {
            for (int i = 0; i < evenLen; i++)
            {
                res.emplace_back(even[i]);
                res.emplace_back(odd[oddLen - 1 - i]);
            }
        }

        return res;
    }
};