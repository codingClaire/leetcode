class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;
        int res = s.length() + 1;
        bool flag = false;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % 2 == 1)
            {
                flag = true;
                res--;
            }
        }
        if (flag == false)
            res--;
        return res;
    }
};