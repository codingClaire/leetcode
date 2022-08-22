class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        unordered_map<int, long long> point;
        for (int i = 0; i < edges.size(); i++)
        {
            if (!point.count(edges[i]))
                point[edges[i]] = 0;
            point[edges[i]] += i;
        }
        int maxv = INT_MIN;
        int maxi = -1;
        for (auto it = point.begin(); it != point.end(); it++)
        {
            if (maxv < it->second)
            {
                maxv = it->second;
                maxi = it->first;
            }
            else if (maxv == it->second)
            {
                if (maxi > it->first)
                    maxi = it->first;
            }
        }
        return maxi;
    }
};