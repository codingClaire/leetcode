class Solution
{
public:
    string largestPalindromic(string num)
    {
        string res = "";
        unordered_map<int, int> mp;
        for (int i = 0; i < num.length(); i++)
        {
            ++mp[num[i] - '0'];
        }
        int single = -1;
        vector<int> doublenum;
        for (int i = 9; i >= 0; i--)
        {
            if (mp.count(i))
            {
                if (single == -1 && mp[i] % 2 == 1)
                {
                    single = i;
                }
                if (mp[i] >= 2)
                {
                    int time = mp[i] / 2;
                    while (time != 0)
                    {
                        doublenum.emplace_back(i);
                        time--;
                    }
                }
            }
        }
        int startindex = 0;
        while (startindex < doublenum.size() && doublenum[startindex] == 0)
        {
            startindex++;
        }
        if (single == -1 && startindex == doublenum.size())
            single = 0;
        if (startindex < doublenum.size())
        {
            for (int i = startindex; i < doublenum.size(); i++)
                res += doublenum[i] + '0';
        }
        if (single != -1 || startindex)
            res += single + '0';
        if (startindex < doublenum.size())
        {
            for (int i = doublenum.size() - 1; i >= startindex; i--)
                res += doublenum[i] + '0';
        }
        return res;
    }
};
