class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int maxvalue = 0;
        int tmp = 1;
        int n = grades.size();
        while (n != 0)
        {
            if (n - tmp >= 0)
                n = n - tmp;
            else
                break;
            tmp++;
            maxvalue++;
        }
        return maxvalue;
    }
};