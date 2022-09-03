class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        unordered_map<char, vector<int>> mp = {
            {'M', {-1}},
            {'P', {-1}},
            {'G', {-1}},
        };
        int lensum = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            lensum += int(garbage[i].length());

            for (const auto &ch : garbage[i])
            {
                mp[ch].emplace_back(i);
            }
        }
        int travelsum = 0;
        char l[3] = {'M', 'P', 'G'};
        for (int i = 0; i < 3; i++)
        {
            int curmax = *max_element(mp[l[i]].begin(), mp[l[i]].end());
            for (int j = 1; j <= curmax; j++)
            {
                travelsum += travel[j - 1];
            }
        }
        return lensum + travelsum;
    }
};