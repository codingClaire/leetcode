class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        char lc = s[0], rc = s[3];
        int left = s[1] - '0', right = s[4] - '0';

        vector<string> res;
        for (int j = lc - 'a'; j <= rc - 'a'; j++)
        {
            for (int i = left; i <= right; i++)
            {
                string s = "";
                s += j + 'a';
                s += i + '0';
                res.emplace_back(s);
            }
        }
        return res;
    }
};