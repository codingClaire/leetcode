
// 100 % 5.28%
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        return s.substr(n, s.length() - 1) + s.substr(0, n);
    }
};
// 66.69 % 94.98%
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};