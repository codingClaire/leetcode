class Solution
{
public:
    int kIncreasing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i)
        {
            vector<int> d;
            int klen = 0;
            //不要求严递增的写法
            for (int j = i; j < n; j += k)
            {
                klen++;
                auto it = upper_bound(d.begin(), d.end(), arr[j]);
                if (it == d.end())
                    d.push_back(arr[j]);
                else
                    *it = arr[j];
            }
            ans += klen - d.size();
        }
        return ans;
    }
};