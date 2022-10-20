class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {   
        vector<int> res;
        res.emplace_back(pref[0]);
        int count = res[0];
        for(int i=1;i<pref.size();i++)
        {
            res.emplace_back(count^pref[i]);
            count = count^res[i];
        }
        return res;
    }
};