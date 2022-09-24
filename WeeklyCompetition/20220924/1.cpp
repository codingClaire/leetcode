class Solution
{
public:
    int temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB)
    {
        int res=0;
        int left =0, right = 0;
        int n= temperatureA.size();
        int tmp = 0;
        for(int i=0;i<n-1;i++)
        {
            right =i+1;
            if(temperatureA[i]== temperatureA[i+1] && temperatureB[i]== temperatureB[i+1])
            {
                res = max(res, right-left);
            }
            else if(temperatureA[i]>temperatureA[i+1] && temperatureB[i]>temperatureB[i+1])
            {
                res = max(res, right-left);
            }
            else if(temperatureA[i]<temperatureA[i+1] && temperatureB[i]<temperatureB[i+1])
            {
                res = max(res, right-left);
            }
            else
            {
                left = i+1;
            }
        }
        return res;
    }
};