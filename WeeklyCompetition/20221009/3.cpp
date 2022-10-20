//WA
class Solution
{
public:
    int solve(string s)
    {
        cout<<"==="<<s<<endl;
        unordered_map<int,string> mp;
        vector<int> keys;
        mp.insert(make_pair(s.length()-1,s.substr(s.length()-1,1)));
        keys.emplace_back(s.length()-1);
        for(int i=s.length()-1;i>0;i--)
        {
            if(s[i-1]<s[i])
            {
                cout<<i-1<<" "<<s.substr(i-1,s.length()-i+1)<<endl;
                mp.insert(make_pair(i-1,s.substr(i-1,s.length()-i+1)));
                keys.emplace_back(i-1);
            }     
        }
        if(keys.size()==0)
            return 0;
        int ans = keys[0];
        string mins = mp[keys[0]];
        cout<<ans<<" "<<mins<<"===="<<endl;
        for(int i=1;i<keys.size();i++)
        {
            //cout<<keys[i]<<" mp:"<<mp[keys[i]]<<endl;
            if(mp[keys[i]]<mins)
            {
                mins=mp[keys[i]];
                ans = keys[i];
            }
        }
        cout<<ans<<" "<<mins<<endl;
        return ans;
    }
    string robotWithString(string s)
    {
        string res = "";
        reverse(s.begin(),s.end()); 
        int curi = s.length()-1;
        int curend =s.length();
        while(curend!=0)
        {
            int curi =solve(s.substr(0,curend));
            //cout<<curi<<" "<<res<<endl;
            res+=s.substr(curi,curi+curend);
            curend = curi;
        }

        return res;
    }
};