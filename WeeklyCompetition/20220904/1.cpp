class Solution
{
public:
    unordered_map<int,int> mp;
    bool checkDistances(string s, vector<int> &distance)
    {
        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i]-'a'))
                mp[s[i]-'a'] = i - mp[s[i]-'a']-1;
            else
                 mp[s[i]-'a'] = i;
        }
        for(int i=0;i<distance.size();i++)
        {
            if(mp.count(i))
            {
                if(mp[i] != distance[i])
                    return false;
            }
        }
        return true;
    }
};