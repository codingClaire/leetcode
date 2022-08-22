class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string res(pattern.size() + 1, '0');
        vector<int> curD(pattern.size(), 0); // "IIIDIDDD"   0 0 0 1 0 3 2 1
        vector<int> curI(pattern.size(), 0); // "IIIDIDDD"   1 2 3 0 1 0 0 0
        int curd = 0, curi = 0;
        for (int i = pattern.size() - 1; i >= 0; i--)
        {
            if (pattern[i] == 'D')
                curd++;
            else
                curd = 0;

            curD[i] = curd;
        }
        for (int i = 0; i < pattern.size(); i++)
        {
            if (pattern[i] == 'I')
                curi++;
            else
                curi = 0;

            curI[i] = curi;
        }
        for (int i = 0; i < pattern.size(); i++)
        {
            if (curI[i] != 0)
            {
                if (i == 0)
                    res[i] += 1;
                else
                {
                    if (curD[i - 1] != 0)
                    {
                        res[i] = res[i - 1] - 1;
                    }
                    else
                        res[i] = *max_element(res.begin(), res.begin() + i) + 1;
                }
                if (i == pattern.size() - 1)
                    res[i + 1] = *max_element(res.begin(), res.begin() + i + 1) + 1;
            }
            else if (curD[i] != 0)
            {
                if (i == 0)
                    res[i] += curD[i] + 1;
                else if (curI[i - 1] != 0)
                {
                    res[i] = *max_element(res.begin(), res.begin() + i) + 1 + curD[i];
                }
                else
                {
                    res[i] = res[i - 1] - 1;
                }
                if (i == pattern.size() - 1)
                    res[i + 1] = res[i] - 1;
            }
        }
        return res;
    }
};
