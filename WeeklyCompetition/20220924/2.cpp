class Solution
{
public:
    int transportationHub(vector<vector<int>> &path)
    {
        unordered_map<int,bool> mp;
        unordered_map<int,int> in_edges;
        for(int i=0;i<path.size();i++)
        {
            in_edges[path[i][1]]++;
            mp[path[i][0]] = false;
            if(!mp.count(path[i][1]) || mp[path[i][1]]!=false)
                mp[path[i][1]] = true;
        }
        int total_num = 0;
        for(auto iter=mp.begin();iter!=mp.end();iter++)
        {
            total_num++;
        }

        for(auto iter=mp.begin();iter!=mp.end();iter++)
        {
            if(iter->second == true && in_edges[iter->first] == total_num-1)
                return iter->first;
        }
        return -1;
    }
};