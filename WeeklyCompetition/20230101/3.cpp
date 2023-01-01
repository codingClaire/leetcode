class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        int res = 0;
        int i = 0, j = 0;
        while (j != s.length())
        {
            if (s[i] - '0' > k)
                return -1;
            long long curnum = s[i] - '0';
            // cout<<curnum<<" ";
            while (curnum <= k)
            {
                j++;
                if (j > s.length() - 1)
                    break;
                curnum *= 10;
                curnum += s[j] - '0';
            }
            // cout<<curnum<<endl;
            i = j;
            // cout<<i<<" "<<j<<endl;
            res++;
        }
        return res;
    }
};