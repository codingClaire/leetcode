class Solution
{
public:
    string removeStars(string s)
    {
        string t;
        for (const auto &c : s)
        {
            // * 作为一个标记
            if (c != '*')
                t += c;
            else
                t.pop_back();
        }
        return t;
    }
};

//我真傻真的
class Solution
{
public:
    string removeStars(string s)
    {
        int slen = s.length();
        int i = slen - 1, j = slen - 1;
        while (i != 0 && j != 0)
        {
            if (s[i] == '*')
            {
                s.erase(i, 1);
                i--;
                j = i;
                while (s[j] == '*')
                {
                    j--;
                }
                s.erase(j, 1);
                i = min(i - 1, int(s.length() - 1));
            }
            else
            {
                i--;
                j--;
            }
        }
        return s;
    }
};