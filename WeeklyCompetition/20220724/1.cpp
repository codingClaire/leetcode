class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> mp;
        for (auto &ch : s)
        {
            if (!mp.count(ch))
            {
                mp[ch] = 1;
            }
            else
            {
                if (mp[ch] == 1)
                    return ch;
            }
        }
        return 'a';
    }
};