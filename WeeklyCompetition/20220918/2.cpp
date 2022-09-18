class Solution {
public:
    int longestContinuousSubstring(string s) 
    {
        int res=0;
        int l = 0, r=0;
        const int len = s.size();
        while(r!=len+1)
        {
            if(r==0 || s[r-1]==s[r]-1)
            {
                res = max(res, r-l+1);
            }
            else
            {
                l=r;
            }
            r++;
        }
        return res;
    }
};