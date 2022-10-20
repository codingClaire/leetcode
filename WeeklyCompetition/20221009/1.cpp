class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int maxv = logs[0][1];
        int ans= logs[0][0];
        for(int i=1;i<logs.size();i++)
        {
            if(maxv<logs[i][1]-logs[i-1][1])
            {
                maxv = logs[i][1]-logs[i-1][1];
                ans = logs[i][0];
            }
            else if(maxv==logs[i][1]-logs[i-1][1])
            {
                if(ans>logs[i][0])
                    ans = logs[i][0];
            }
        }
        return ans;
    }
};