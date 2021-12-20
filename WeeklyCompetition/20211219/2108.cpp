class Solution
{
public:
    bool isPalindrome(string a)
    {
        int len = a.length();
        for (int i = 0; i < len; i++)
        {
            if (a[i] != a[len - 1 - i])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};